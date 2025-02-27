/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:01:40 by akumari           #+#    #+#             */
/*   Updated: 2025/02/27 15:57:14 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->map_row = get_map_row(game->map);
	game->map_col = ft_strlen(game->map[0]);
	game->move_count = 0;
	game->mlx = mlx_init(game->map_col * TILE_SIZE, game->map_row * TILE_SIZE,
			"so_long", true);
	if (!game->mlx)
		return (0);
	load_textures(game);
	load_images(game);
	render_map(game, game->map_image);
	mlx_key_hook(game->mlx, key_press, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->map_texture);
	free(game->map_image);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	size_t	len;

	if (argc != 2)
	{
		printf("\e[33mTry: ./so_long <MAP>.ber \e[0m\n");
		return (EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (len >= 4 && ft_strcmp(argv[1] + len - 4, ".ber") == 0)
	{
		printf("The file has a .ber extension.\n");
		game.map = read_map(argv[1]);
		if (game.map == NULL)
			return (1);
		printf("Printing the map.\n");
		print_map(game.map);
		if (!validate_map(game.map))
			return (free_map(game.map), 1);
		printf("Map is valid.\n");
		if (!valid_path(game.map, &game))
			printf("Path Invalid\n");
		player_pos_and_get_collec_and_exit(&game);
		if (init_game(&game) == 1)
			printf("You Won!!!\n");
		else
			printf("problem in initializing the game.\n");
	}
	else
	{
		printf("The file does not have a .ber extension.\n");
		return (1);
	}
	return (0);
}
