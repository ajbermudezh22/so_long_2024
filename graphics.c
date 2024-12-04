/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:44:38 by albbermu          #+#    #+#             */
/*   Updated: 2024/12/04 07:53:41 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_game(t_game *game)
{
	int	x;
	int	y;
	void	*img;

	x = 0;
	y = 0;
	while (y < game->map_height)
	{
		while (x < game->map_width)
		{
			img = game->textures.floor;
			if (game->map[y][x] == '1')
				img = game->textures.wall;
			else if (game->map[y][x] == 'C')
				img = game->textures.collectible;
			else if (game->map[y][x] == 'E')
				img = game->textures.exit;
			mlx_put_image_to_window(game->mlx, game->window, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->textures.player, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}
