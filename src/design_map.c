/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:37:54 by akumari           #+#    #+#             */
/*   Updated: 2025/02/27 13:10:14 by akumari          ###   ########.fr       */
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
	game->map_texture->space = mlx_load_png("./assets/space.png");
	game->map_texture->wall = mlx_load_png("./assets/wall.png");
	game->map_texture->collectible = mlx_load_png("./assets/coin.png");
	game->map_texture->character = mlx_load_png("./assets/player.png");
	game->map_texture->exit = mlx_load_png("./assets/exit.png");
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

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_player(game, 0, -1);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_player(game, -1, 0);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_player(game, 0, 1);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_player(game, 1, 0);
}

void	move_player(t_game *game, int pos_x, int pos_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos->x + pos_x;
	new_y = game->player_pos->y + pos_y;
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectibles--;
		if (game->map[new_y][new_x] == 'E')
		{
			if (game->collectibles == 0)
			{
				printf("Player reached the exit. Moving to exit...\n");
				mlx_close_window(game->mlx);
				return ;
			}
			else
			{
				printf("You must collect all items before exiting!\n");
				return ;
			}
		}
		game->map[game->player_pos->y][game->player_pos->x] = '0';
		game->player_pos->x = new_x;
		game->player_pos->y = new_y;
		game->map[new_y][new_x] = 'P';
		render_map(game, game->map_image);
		game->move_count++;
		printf("%i\n", game->move_count);
	}
}
