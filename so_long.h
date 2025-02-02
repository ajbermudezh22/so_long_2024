/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:10:02 by albbermu          #+#    #+#             */
/*   Updated: 2025/01/07 09:56:21 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# define TILE_SIZE 64

typedef struct s_texture
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			move_count;
	int			collectibles;
	int			collected;
	t_texture	textures;
}	t_game;

typedef struct s_map_info
{
	int	start_x;
	int	start_y;
	int	total_collectibles;
	int	reach_exits;
	int	reach_collectibles;
}	t_map_info;

typedef struct s_map_elements
{
	int	exit_count;
	int	start_count;
	int	collectible_count;
}	t_map_elements;

// accessibility
int		validate_accesibility(char **map, int height, int width);

// game logic
void	init_game(t_game *game);
void	init_texture(t_texture *texture);

// graphics
void	render_game(t_game *game);

// keyboard
int		key_handler(int keycode, t_game *game);
int		close_handler(t_game *game);
int		loop_handler(t_game *game);
void	setup_hooks(t_game *game);
void	move_player(t_game *game, char direction);
void	free_game_resources(t_game *game);

// map utils
void	map_error(char *s);
void	load_textures(t_game *game, t_texture *textures);
int		open_map_file(const char *filename);
char	**resize_map_mem(char **map, int line_count);
void	check_empty_map(int line_count, char **map);

// parse map
char	**read_map_file(const char *filename, int *height);
void	parse_map(t_game *game, const char *filename);

// validate map
int		is_map_rectangular(char **map, int height);
int		is_map_enclosed(char **map, int height);
int		validate_map_elements(char **map, int height);
void	validate_map(char **map, int height);

#endif