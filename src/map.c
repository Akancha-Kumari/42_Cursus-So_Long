/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:28:51 by akumari           #+#    #+#             */
/*   Updated: 2025/02/28 14:18:37 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <ctype.h>

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
int is_empty_map(const char *str)
{
    if(!str || !str[0])
		return (0);
    return (1);
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
	{
		printf("Error: Could not open file %s\n", map);
		return (free(temp_map), NULL);
	}
	fileread = read(fd, temp_map, BUFFER_SIZE);
	if (fileread <= 0 || !(is_empty_map(map)))
		return (printf(EMPTY_MAP), close(fd), free(temp_map), NULL);
	get_map = ft_split(temp_map, '\n');
	if (get_map == NULL)
		return (close(fd), free(temp_map), NULL);
	free(temp_map);
	close(fd);
	return (get_map);
}
