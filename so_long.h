/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:10:02 by albbermu          #+#    #+#             */
/*   Updated: 2024/11/27 13:37:43 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		move_count;
	int		collectibles;
	int		collected;
}	t_game;

typedef struct s_texture
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_texture;

#endif