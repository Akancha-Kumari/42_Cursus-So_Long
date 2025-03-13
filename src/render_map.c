/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:56:07 by akumari           #+#    #+#             */
/*   Updated: 2025/03/08 15:01:52 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	initialize_map_backup(t_game *game)
{
	int	y;
	int	x;

	game->map_backup = malloc(sizeof(char *) * (game->map_row + 1));
	if (!game->map_backup)
		return ;
	y = 0;
	while (y < game->map_row)
	{
		game->map_backup[y] = malloc(sizeof(char) * (game->map_col + 1));
		if (!game->map_backup[y])
			return ;
		x = 0;
		while (x < game->map_col)
		{
			game->map_backup[y][x] = game->map[y][x];
			x++;
		}
		game->map_backup[y][x] = '\0';
		y++;
	}
	game->map_backup[y] = NULL;
}
