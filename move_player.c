/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:41:53 by albermud          #+#    #+#             */
/*   Updated: 2025/01/07 09:53:16 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_new_position(int *new_x, int *new_y,
	char direction, t_game *game)
{
	if (direction == 'W' && *new_y > 0 && game->map[*new_y - 1][*new_x] != '1')
		(*new_y)--;
	else if (direction == 'S' && *new_y < game->map_height - 1
		&& game->map[*new_y + 1][*new_x] != '1')
		(*new_y)++;
	else if (direction == 'A' && *new_x > 0
		&& game->map[*new_y][*new_x - 1] != '1')
		(*new_x)--;
	else if (direction == 'D' && *new_x < game->map_width - 1
		&& game->map[*new_y][*new_x + 1] != '1')
		(*new_x)++;
}

static void	check_collectible(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
		ft_printf("Collected a collectible! Total: %d/%d\n",
			game->collected, game->collectibles);
	}
}

static void	update_position_and_move_count(t_game *game, int new_x, int new_y)
{
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	ft_printf("Player moved to: (%d, %d). Moves: %d\n", new_x, new_y,
		game->move_count);
}

static void	check_exit(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("You collected all collectibles and exited the game! "
				"Total moves: %d\n", game->move_count);
			free_game_resources(game);
			exit(EXIT_SUCCESS);
		}
		else
		{
			ft_printf("You need to collect all collectibles before exiting!\n");
		}
	}
}

void	move_player(t_game *game, char direction)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	get_new_position(&new_x, &new_y, direction, game);
	check_collectible(game, new_x, new_y);
	update_position_and_move_count(game, new_x, new_y);
	check_exit(game);
}
