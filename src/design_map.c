/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:37:54 by akumari           #+#    #+#             */
/*   Updated: 2025/02/28 12:13:27 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->map_texture = ft_calloc(1, sizeof(t_textures));
	if (!game->map_texture)
	{
		printf("Error: Failed to load texture\n");
		if (game->mlx)
			mlx_terminate(game->mlx);
		return ;
	}
	game->map_texture->space = mlx_load_png("./textures/space.png");
	game->map_texture->wall = mlx_load_png("./textures/wall.png");
	game->map_texture->collectible = mlx_load_png("./textures/coin.png");
	game->map_texture->character = mlx_load_png("./textures/player.png");
	game->map_texture->exit = mlx_load_png("./textures/exit.png");
}

void	load_images(t_game *game)
{
	game->map_image = ft_calloc(1, sizeof(t_images));
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
	mlx_delete_texture(game->map_texture->space);
	mlx_delete_texture(game->map_texture->wall);
	mlx_delete_texture(game->map_texture->collectible);
	mlx_delete_texture(game->map_texture->character);
	mlx_delete_texture(game->map_texture->exit);
}

void	render_map(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, image->space, x * TILE_SIZE, y
				* TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, image->wall, x * TILE_SIZE, y
					* TILE_SIZE);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, image->exit, x * TILE_SIZE, y
					* TILE_SIZE);
			x++;
		}
		y++;
	}
	render_rest_map(game, image);
}

void	render_rest_map(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, image->collectible, x
					* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, image->character, x * TILE_SIZE,
					y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
