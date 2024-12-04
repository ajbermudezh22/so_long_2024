/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:36:48 by albermud          #+#    #+#             */
/*   Updated: 2024/12/04 09:28:08 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int *reach_exits, int *reach_collectibles)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
		(*reach_exits)++;
	else if (map[y][x] == 'C')
		(*reach_collectibles)++;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, reach_exits, reach_collectibles);
	flood_fill(map, x - 1, y, reach_exits, reach_collectibles);
	flood_fill(map, x, y + 1, reach_exits, reach_collectibles);
	flood_fill(map, x, y - 1, reach_exits, reach_collectibles);
}

void	find_start_position(char **map, int height, int width, int *start_x, int *start_y, int *total_collectibles)
{
	int y;
	int x;

	*start_x = -1;
	*start_y = -1;
	*total_collectibles = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
			}
			else if (map[y][x] == 'C')
				(*total_collectibles)++;
			x++;
		}
		y++;
	}
}
int	validate_accesibility(char **map, int height, int width)
{
	int	start_y;
	int	start_x;
	int	total_collectibles;
	int	reach_exits;
	int	reach_collectibles;

	reach_exits = 0;
	reach_collectibles = 0;
	find_start_position(map, height, width, &start_x, &start_y, &total_collectibles);
	if (start_x == -1 || start_y == -1)
	{
		ft_printf("Error\nStart position not found in map\n");
		return (0);
	}
	flood_fill(map, start_x, start_y, &reach_exits, &reach_collectibles);
	if (reach_exits == 0)
	{
		ft_printf("Error\nExit is not accessible from the start position");
		return (0);
	}
	if (reach_collectibles != total_collectibles)
	{
		ft_printf("Error\nNot all collectibles are accessible from the start position\n");
		return (0);
	}
	return (1);
}