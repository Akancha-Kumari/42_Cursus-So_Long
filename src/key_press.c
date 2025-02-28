/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:59:01 by akumari           #+#    #+#             */
/*   Updated: 2025/02/28 14:16:27 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_with_components(t_game *game, int new_x, int new_y)
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
}

void	move_player(t_game *game, int pos_x, int pos_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos->x + pos_x;
	new_y = game->player_pos->y + pos_y;
	if (game->map[new_y][new_x] != '1')
	{
		check_with_components(game, new_x, new_y);
		if(game->map[new_y][new_x] != 'E')
		{
			game->map[game->player_pos->y][game->player_pos->x] = '0';
			game->player_pos->x = new_x;
			game->player_pos->y = new_y;
			game->map[new_y][new_x] = 'P';
			render_map(game, game->map_image);
			game->move_count++;
			printf("%i\n", game->move_count);
		}
	}
}
