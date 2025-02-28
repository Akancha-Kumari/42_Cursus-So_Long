/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:01:40 by akumari           #+#    #+#             */
/*   Updated: 2025/02/28 16:39:08 by akumari          ###   ########.fr       */
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
	{
		free_map(game->map);
		return (0);
	}
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

int	input_check(int argc, char *param)
{
	size_t	len;

	if (argc != 2)
		return (printf(FILE_MSG), 0);
	else
	{
		len = ft_strlen(param);
		if (len >= 4 && ft_strcmp(param + len - 4, ".ber") == 0)
			return (1);
		else
			return (printf(FILE_EXT_MSG), 0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*param;
	
	param = argv[1];
	if (input_check(argc, param))
	{
		game.map = read_map(argv[1]);
		if (game.map == NULL)
			return (1);
		if (!validate_map(game.map))
			return (free_map(game.map), 1);
		if (!valid_path(game.map, &game))
			return (printf(PATH_MSG), free_map(game.map), 1);
		player_pos_and_get_collec_and_exit(&game);
		if (!init_game(&game))
		{
			free_map(game.map);
			free(game.map_texture);
			free(game.map_image);
			free(game.player_pos);
			return (printf(INIT_GAME), 1);
		}	
		free_game(&game);
	}
	return (0);
}

