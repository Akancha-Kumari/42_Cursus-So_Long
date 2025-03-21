/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:35:49 by akumari           #+#    #+#             */
/*   Updated: 2025/03/05 13:20:42 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	dfs_map(char **map, int y, int x, t_game *game)
{
	if (x < 0 || y < 0 || y >= game->map_row || x >= game->map_col)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C' && game->collectibles > 0)
		game->collectibles--;
	if (map[y][x] == 'E' && game->exit > 0)
		game->exit--;
	map[y][x] = 'V';
	dfs_map(map, y + 1, x, game);
	dfs_map(map, y - 1, x, game);
	dfs_map(map, y, x + 1, game);
	dfs_map(map, y, x - 1, game);
}

char	**temp_map(char **map, int row)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (row + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < row)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[row] = NULL;
	return (new_map);
}

void	initialize_variables(t_game *game)
{
	game->collectibles = 0;
	game->exit = 0;
	game->map_row = get_map_row(game->map);
	game->map_col = ft_strlen(game->map[0]);
	game->player_pos.x = -1;
	game->player_pos.y = -1;
}

void	player_pos_and_get_collec_and_exit(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	initialize_variables(game);
	while (y < game->map_row)
	{
		x = 0;
		while (x < game->map_col)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_pos.x = x;
				game->player_pos.y = y;
			}
			else if (game->map[y][x] == 'C')
				game->collectibles++;
			else if (game->map[y][x] == 'E')
				game->exit++;
			x++;
		}
		y++;
	}
}

int	valid_path(char **map, t_game *game)
{
	int		col;
	int		row;
	char	**copy_map;

	col = ft_strlen(map[0]);
	row = get_map_row(map);
	game->map_col = col;
	game->map_row = row;
	copy_map = temp_map(map, row);
	if (copy_map == NULL)
		return (0);
	player_pos_and_get_collec_and_exit(game);
	dfs_map(copy_map, game->player_pos.y, game->player_pos.x, game);
	free_map(copy_map);
	if (game->collectibles == 0 && game->exit == 0)
		return (1);
	else
		return (0);
}
