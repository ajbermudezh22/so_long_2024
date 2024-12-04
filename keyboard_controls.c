/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:47:23 by albbermu          #+#    #+#             */
/*   Updated: 2024/12/04 09:24:05 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(EXIT_FAILURE);
	}
	else if (keycode == 13 || keycode == 126)
		move_player(game, 'W');
	else if (keycode == 0 || keycode == 123)
		move_player(game, 'A');
	else if (keycode == 1 || keycode == 125)
		move_player(game, 'S');
	else if (keycode == 2 || keycode == 124)
		move_player(game, 'D');
	return (0);
}

void	move_player(t_game *game, char direction)
{
	if (direction == 'W' && game->map[game->player_y - 1][game->player_x] != '1')
		game->player_y--;
	else if (direction == 'S' && game->map[game->player_y + 1][game->player_x] != '1')
		game->player_y++;
	else if (direction == 'A' && game->map[game->player_y][game->player_x - 1] != '1')
		game->player_x--;
	else if (direction == 'D' && game->map[game->player_y][game->player_x + 1] != '1')
		game->player_x++;

	game->move_count++;
}


int	close_handler(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

int	loop_handler(t_game *game)
{
	render_game(game);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->window, key_handler, game);
	mlx_hook(game->window, 17, 0, close_handler, game);
	mlx_loop_hook(game->mlx, loop_handler, game);
}
