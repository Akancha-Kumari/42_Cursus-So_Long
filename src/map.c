/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:28:51 by akumari           #+#    #+#             */
/*   Updated: 2025/03/11 11:37:01 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_row(char **map)
{
	int	count;

	count = 0;
	while (map[count])
	{
		count++;
	}
	return (count);
}

int	is_empty_map(const char *str)
{
	if (!str || !str[0])
		return (0);
	return (1);
}

int	has_empty_lines(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_map_size(char **map)
{
	int	max_col;
	int	max_row;
	int	col;
	int	row;

	max_col = SCREEN_WIDTH / TILE_SIZE;
	max_row = SCREEN_HEIGHT / TILE_SIZE;
	col = ft_strlen(map[0]);
	row = get_map_row(map);
	if (!map || !map[0])
		return (0);
	if (col > max_col)
	{
		ft_printf("Error\nMap width (%d) exceeds screen limit (%d columns max)\n",
			col, max_col);
		return (1);
	}
	if (row > max_row)
	{
		ft_printf("Error\nMap height (%d) exceeds screen limit (%d rows max)\n",
			row, max_row);
		return (1);
	}
	return (0);
}

char	**read_map(char *map)
{
	char	*temp_map;
	int		fd;
	int		fileread;
	char	**get_map;

	temp_map = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_map)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nCould not open file %s\n", map),
			free(temp_map), NULL);
	fileread = read(fd, temp_map, BUFFER_SIZE);
	if (fileread <= 0 || !(is_empty_map(map)))
		return (ft_printf(EMPTY_MAP), close(fd), free(temp_map), NULL);
	if (has_empty_lines(temp_map))
		return (ft_printf(SPACES_MAP), free(temp_map), NULL);
	get_map = ft_split(temp_map, '\n');
	if (get_map == NULL)
		return (close(fd), free(temp_map), NULL);
	if (check_map_size(get_map))
		return (free_map(get_map), NULL);
	free(temp_map);
	close(fd);
	return (get_map);
}
