/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:47:58 by akumari           #+#    #+#             */
/*   Updated: 2025/03/08 14:34:13 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_backup(char **map_backup)
{
	int	i;

	i = 0;
	while (map_backup[i])
	{
		free(map_backup[i]);
		i++;
	}
	free(map_backup);
}

void	free_all(t_game *game)
{
	free_map(game->map);
	free(game->map_texture);
	free(game->map_image);
	free_map_backup(game->map_backup);
}
