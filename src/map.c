/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:28:51 by akumari           #+#    #+#             */
/*   Updated: 2025/02/27 15:31:28 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	if (!map)
	{
		printf("Error: Map is NULL\n");
		return ;
	}
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
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
		free(temp_map);
		printf("Error: Could not open file %s\n", map);
		return (NULL);
	}
	fileread = read(fd, temp_map, BUFFER_SIZE);
	if (fileread <= 0)
	{
		free(temp_map);
		close(fd);
		return (0);
	}
	get_map = ft_split(temp_map, '\n');
	if (get_map == NULL)
	{
		free(temp_map);
		close(fd);
		return (NULL);
	}
	free(temp_map);
	close(fd);
	return (get_map);
}
//	printf("Openfile - %d\n", fd);
//	printf("readfile - %d\n", fileread);
// void	design_map(t_game *game, char **map)
// {
// 	game->number_of_collectible = total_collectible(map);
// 	game->map_col = ft_strlen(map[0]) * 32;
// 	game->map_row = get_map_row(map) * 32;
// }

// int	total_collectible(char **map)
// {
// 	int	count;
// 	int	i;
// 	int	j;

// 	count = 0;
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'C')
// 				count++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }