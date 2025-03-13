/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:27:56 by akumari           #+#    #+#             */
/*   Updated: 2025/03/12 12:38:05 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_is_rectangle(char **map)
{
	int	width;
	int	i;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	surrounded_by_walls(char **map)
{
	int	col;
	int	row;
	int	i;

	col = ft_strlen(map[0]);
	row = get_map_row(map);
	i = 0;
	while (i < col)
	{
		if (map[0][i] != '1' || map[row - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (map[i][0] != '1' || map[i][col - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_characters(char **map, int *player_count, int *exit_count,
		int *collectible_count)
{
	int	row;
	int	i;
	int	j;

	row = get_map_row(map);
	i = 0;
	while (i < row)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*player_count)++;
			else if (map[i][j] == 'E')
				(*exit_count)++;
			else if (map[i][j] == 'C')
				(*collectible_count)++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(char **map)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	if (!map_is_rectangle(map))
		return (ft_printf(RECTANGLE_MAP), 0);
	if (!surrounded_by_walls(map))
		return (ft_printf(WALL_MSG), 0);
	if (!validate_characters(map, &player_count, &exit_count,
			&collectible_count))
		return (ft_printf(WRONG_COMP), 0);
	if (player_count != 1)
		return (ft_printf(PLAYER_COUNT), 0);
	if (exit_count != 1)
		return (ft_printf(EXIT_COUNT), 0);
	if (collectible_count == 0)
		return (ft_printf(COLLECTIBLE_COUNT), 0);
	return (1);
}
