/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:09:20 by albbermu          #+#    #+#             */
/*   Updated: 2025/01/06 13:51:34 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_game *game)
{
	ft_printf("Creating game window...\n");
	game->window = mlx_new_window(game->mlx,
			game->map_width * TILE_SIZE, game->map_height * TILE_SIZE,
			"So Long Game");
	if (!game->window)
		map_error("Failed to create window");
	ft_printf("Game window created successfully.\n");
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		map_error("Usage: ./so_long <map_file>");
	init_game(&game);
	parse_map(&game, av[1]);
	create_window(&game);
	load_textures(&game, &game.textures);
	render_game(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
