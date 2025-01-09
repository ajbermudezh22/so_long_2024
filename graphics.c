/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:44:38 by albbermu          #+#    #+#             */
/*   Updated: 2025/01/07 09:44:31 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int x, int y)
{
	void	*img;

	img = game->textures.floor;
	if (game->map[y][x] == '1')
		img = game->textures.wall;
	else if (game->map[y][x] == 'C')
		img = game->textures.collectible;
	else if (game->map[y][x] == 'E')
		img = game->textures.exit;
	mlx_put_image_to_window(game->mlx, game->window, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->textures.player,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}
