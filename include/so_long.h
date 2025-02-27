/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:35:14 by akumari           #+#    #+#             */
/*   Updated: 2025/02/27 15:56:11 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h> //For debugging
#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <unistd.h>  //for write
#include <fcntl.h>

#define WIDTH 800
#define HEIGHT 800
#define BUFFER_SIZE 10000
#define TILE_SIZE 128

typedef struct s_game
{
	mlx_t *mlx;
	char **map;
	int number_of_collectible;
	int map_row;
	int map_col;
	int exit;
	struct s_textures	*map_texture;
	struct s_images		*map_image;
	struct s_pos		*player_pos;
	int					move_count;
	int 				collectibles;

} t_game;

typedef struct s_pos
{
	int x;
	int y;
} t_pos;

typedef struct s_textures {
	mlx_texture_t	*space;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*character;
	mlx_texture_t	*exit;
}				t_textures;

typedef struct s_images {
	mlx_image_t	*space;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*character;
	mlx_image_t	*exit;
}				t_images;

//void 	design_map(t_game *game, char **map);
void	free_map(char **map);

//LIBFT functions
int 	ft_strlen(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(char *src);


//map read
void 	*ft_calloc(size_t count, size_t size);
char	**read_map(char *map);
void 	print_map(char **map);


//validate map
int 	validate_map(char **map);
int 	map_is_rectangle(char **map);
int 	surrounded_by_walls(char **map);
int 	get_map_row(char **map);
int 	validate_characters(char **map, int *player_count, int *exit_count, int *collectible_count);


//valid path
int		valid_path(char **map, t_game *game);
void 	player_pos_and_get_collec_and_exit(t_game *game);
char 	**temp_map(char **map, int row);
void	dfs_map(char **map, int y, int x, t_game *game);

//Init_Game
void	load_textures(t_game *game);
void	load_images(t_game *game);
void	render_map(t_game *game, t_images *image);
void 	key_press(mlx_key_data_t keydata, void *param);
void 	move_player(t_game *game, int pos_x, int pos_y);

//int 	total_collectible(char **map);
//t_pos 	player_start_pos(char **map, int column, int row);
//int 	exit_count(char **map, int row, int col);
#endif