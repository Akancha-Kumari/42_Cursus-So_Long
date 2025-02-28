/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:35:14 by akumari           #+#    #+#             */
/*   Updated: 2025/02/28 16:21:46 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <stdio.h> //For debugging
# include <stdlib.h>
# include <unistd.h> //for write

// # define WIDTH 800
// # define HEIGHT 800
# define BUFFER_SIZE 10000
# define TILE_SIZE 128

# define FILE_MSG "Error:\e[33mTry-> ./so_long <MAP>.ber \e[0m\n"
# define FILE_EXT_MSG "Error: Invalid file extension.\n"
# define PATH_MSG "Error: Map path Invalid.\n"
# define PLAYER_COUNT "Error: Map must contain exactly one player (P).\n"
# define COLLECT_EXIT_COUNT "Error: At least one exit & collectible required.\n"
# define RECTANGLE_MAP "Error: Map is not rectangle.\n"
# define WALL_MSG "Error: Map is not surrounded by walls\n"
# define INIT_GAME "Error: Problem in initializing the game.\n"
# define WRONG_COMP "Error: Map has wrong components.\n"
# define EMPTY_MAP "Error: Map is empty.\n"

typedef struct s_game
{
	mlx_t				*mlx;
	char				**map;
	int					number_of_collectible;
	int					map_row;
	int					map_col;
	int					exit;
	struct s_textures	*map_texture;
	struct s_images		*map_image;
	struct s_pos		*player_pos;
	int					move_count;
	int					collectibles;

}						t_game;

typedef struct s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct s_textures
{
	mlx_texture_t		*space;
	mlx_texture_t		*wall;
	mlx_texture_t		*collectible;
	mlx_texture_t		*character;
	mlx_texture_t		*exit;
}						t_textures;

typedef struct s_images
{
	mlx_image_t			*space;
	mlx_image_t			*wall;
	mlx_image_t			*collectible;
	mlx_image_t			*character;
	mlx_image_t			*exit;
}						t_images;

// Initial checks
int						input_check(int argc, char *param);
void 					initialize_variables(t_game *game);
// Free
void					free_map(char **map);
void free_game(t_game *game);

// LIBFT functions
int						ft_strlen(char *str);
int						ft_strcmp(const char *s1, const char *s2);
char					**ft_split(char const *s, char c);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_strdup(char *src);

// map read
void					*ft_calloc(size_t count, size_t size);
char					**read_map(char *map);
int 					is_empty_map(const char *str);

// validate map
int 					map_is_empty(char **map);
int						validate_map(char **map);
int						map_is_rectangle(char **map);
int						surrounded_by_walls(char **map);
int						get_map_row(char **map);
int						validate_characters(char **map, int *player_count,
							int *exit_count, int *collectible_count);

// valid path
int						valid_path(char **map, t_game *game);
void					player_pos_and_get_collec_and_exit(t_game *game);
char					**temp_map(char **map, int row);
void					dfs_map(char **map, int y, int x, t_game *game);

// Init_Game
void					load_textures(t_game *game);
void					load_images(t_game *game);
void					render_map(t_game *game, t_images *image);
void					render_rest_map(t_game *game, t_images *image);

// Key Press
void					key_press(mlx_key_data_t keydata, void *param);
void					move_player(t_game *game, int pos_x, int pos_y);
void					check_with_components(t_game *game, int new_x,
							int new_y);

//void					print_map(char **map);
#endif