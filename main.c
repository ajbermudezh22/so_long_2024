/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:09:20 by albbermu          #+#    #+#             */
/*   Updated: 2024/12/04 09:19:00 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		ft_printf("Error\nFailed to initialize Minilibx\n");
		exit(EXIT_FAILURE);
	}
	game->window = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
		game->map_height * TILE_SIZE, "So Long Game");
	if (game->window == NULL)
	{
		ft_printf("Error\nFailed to create window\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
    t_game	game;

	if (ac == 1)
		map_error("Please specify a map");
	else if (ac > 2)
		map_error("Too many arguments");
	init_game(&game);
	init_texture(&game.textures);
	parse_map(&game, av[1]);
	create_window(&game);
	load_textures(&game, &game.textures);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
