/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:37:54 by akumari           #+#    #+#             */
/*   Updated: 2025/03/08 15:14:55 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_textures(t_game *game)
{
	game->map_texture = ft_calloc(1, sizeof(t_textures));
	if (!game->map_texture)
	{
		ft_printf("Error\nFailed to load texture\n");
		if (game->mlx)
			mlx_terminate(game->mlx);
		return ;
	}
	game->map_texture->space = mlx_load_png("./textures/space.png");
	game->map_texture->wall = mlx_load_png("./textures/wall.png");
	game->map_texture->collectible = mlx_load_png("./textures/coin.png");
	game->map_texture->character = mlx_load_png("./textures/player.png");
	game->map_texture->exit = mlx_load_png("./textures/exit.png");
	check_texture_load(game);
}

void	load_images(t_game *game)
{
	game->map_image = ft_calloc(1, sizeof(t_images));
	if (!game->map_image)
		return ;
	game->map_image->space = mlx_texture_to_image(game->mlx,
			game->map_texture->space);
	game->map_image->wall = mlx_texture_to_image(game->mlx,
			game->map_texture->wall);
	game->map_image->collectible = mlx_texture_to_image(game->mlx,
			game->map_texture->collectible);
	game->map_image->character = mlx_texture_to_image(game->mlx,
			game->map_texture->character);
	game->map_image->exit = mlx_texture_to_image(game->mlx,
			game->map_texture->exit);
	check_image_load(game);
	mlx_delete_texture(game->map_texture->space);
	mlx_delete_texture(game->map_texture->wall);
	mlx_delete_texture(game->map_texture->collectible);
	mlx_delete_texture(game->map_texture->character);
	mlx_delete_texture(game->map_texture->exit);
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->map_image->wall, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (tile == '0')
		mlx_image_to_window(game->mlx, game->map_image->space, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (tile == 'E')
	{
		mlx_image_to_window(game->mlx, game->map_image->space, x * TILE_SIZE, y
			* TILE_SIZE);
		mlx_image_to_window(game->mlx, game->map_image->exit, x * TILE_SIZE, y
			* TILE_SIZE);
	}
	render_tile2(game, x, y);
}

void	render_tile2(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == 'P')
	{
		mlx_image_to_window(game->mlx, game->map_image->space, x * TILE_SIZE, y
			* TILE_SIZE);
		if (game->map_backup[y][x] == 'E')
		{
			mlx_image_to_window(game->mlx, game->map_image->exit, x * TILE_SIZE,
				y * TILE_SIZE);
		}
		mlx_image_to_window(game->mlx, game->map_image->character, x
			* TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == 'C')
	{
		mlx_image_to_window(game->mlx, game->map_image->space, x * TILE_SIZE, y
			* TILE_SIZE);
		mlx_image_to_window(game->mlx, game->map_image->collectible, x
			* TILE_SIZE, y * TILE_SIZE);
	}
}
