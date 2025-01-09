/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:47:23 by albbermu          #+#    #+#             */
/*   Updated: 2025/01/07 09:46:41 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_textures(t_game *game)
{
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.collectible)
		mlx_destroy_image(game->mlx, game->textures.collectible);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
}

void	free_game_resources(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free_textures(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
	{
		free_game_resources(game);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13 || keycode == 119)
		move_player(game, 'W');
	else if (keycode == 1 || keycode == 115)
		move_player(game, 'S');
	else if (keycode == 0 || keycode == 97)
		move_player(game, 'A');
	else if (keycode == 2 || keycode == 100)
		move_player(game, 'D');
	render_game(game);
	return (0);
}

int	close_handler(t_game *game)
{
	free_game_resources(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, key_handler, game);
	mlx_hook(game->window, 17, 0, close_handler, game);
}
