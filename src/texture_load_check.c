/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:37:27 by akumari           #+#    #+#             */
/*   Updated: 2025/03/08 13:03:09 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_texture_load(t_game *game)
{
	if (!game->map_texture->space || !game->map_texture->wall
		|| !game->map_texture->collectible || !game->map_texture->character
		|| !game->map_texture->exit)
	{
		ft_printf("Error\nFailed to load one or more textures\n");
		if (game->map_texture->space)
			mlx_delete_texture(game->map_texture->space);
		if (game->map_texture->wall)
			mlx_delete_texture(game->map_texture->wall);
		if (game->map_texture->collectible)
			mlx_delete_texture(game->map_texture->collectible);
		if (game->map_texture->character)
			mlx_delete_texture(game->map_texture->character);
		if (game->map_texture->exit)
			mlx_delete_texture(game->map_texture->exit);
		free(game->map_texture);
		if (game->mlx)
			mlx_terminate(game->mlx);
		exit(1);
	}
}

void	check_image_load(t_game *game)
{
	if (!game->map_image->space || !game->map_image->wall
		|| !game->map_image->collectible || !game->map_image->character
		|| !game->map_image->exit)
	{
		ft_printf("Error\nFailed to convert one or more textures to images\n");
		if (game->map_image->space)
			mlx_delete_image(game->mlx, game->map_image->space);
		if (game->map_image->wall)
			mlx_delete_image(game->mlx, game->map_image->wall);
		if (game->map_image->collectible)
			mlx_delete_image(game->mlx, game->map_image->collectible);
		if (game->map_image->character)
			mlx_delete_image(game->mlx, game->map_image->character);
		if (game->map_image->exit)
			mlx_delete_image(game->mlx, game->map_image->exit);
		free(game->map_image);
		free(game->map_texture);
		if (game->mlx)
			mlx_terminate(game->mlx);
		exit(1);
	}
}
