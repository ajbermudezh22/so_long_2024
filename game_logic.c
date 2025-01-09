/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:44:16 by albbermu          #+#    #+#             */
/*   Updated: 2025/01/06 13:45:52 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->window = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->move_count = 0;
	game->collectibles = 0;
	game->collected = 0;
}

void	init_texture(t_texture *texture)
{
	texture->wall = NULL;
	texture->floor = NULL;
	texture->collectible = NULL;
	texture->exit = NULL;
	texture->player = NULL;
}
