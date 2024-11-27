/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:09:20 by albbermu          #+#    #+#             */
/*   Updated: 2024/11/27 14:56:03 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	main(int ac, char **av)
{
    t_game	game;

	if (ac == 1)
		map_error("Please specify a map");
	else if (ac > 2)
		map_error("Too many arguments");
	game.mlx = mlx_init();
	
}
