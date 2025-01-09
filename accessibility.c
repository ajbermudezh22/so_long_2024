/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:36:48 by albermud          #+#    #+#             */
/*   Updated: 2025/01/06 13:44:53 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_map_info *info)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
		info->reach_exits++;
	else if (map[y][x] == 'C')
		info->reach_collectibles++;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, info);
	flood_fill(map, x - 1, y, info);
	flood_fill(map, x, y + 1, info);
	flood_fill(map, x, y - 1, info);
}

void	find_start_position(char **map, int h, int w, t_map_info *info)
{
	int	y;
	int	x;

	info->start_x = -1;
	info->start_y = -1;
	info->total_collectibles = 0;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (map[y][x] == 'P')
			{
				info->start_x = x;
				info->start_y = y;
			}
			else if (map[y][x] == 'C')
				info->total_collectibles++;
			x++;
		}
		y++;
	}
}

int	check_start_position(t_map_info *info)
{
	if (info->start_x == -1 || info->start_y == -1)
	{
		ft_printf("Error\nStart position not found in map\n");
		return (0);
	}
	return (1);
}

int	check_accessibility(t_map_info *info)
{
	if (info->reach_exits == 0)
	{
		ft_printf("Error\nExit is not accessible from the start position");
		return (0);
	}
	if (info->reach_collectibles != info->total_collectibles)
	{
		ft_printf("Error\n"
			"Not all collectibles are accessible from the start\n");
		return (0);
	}
	return (1);
}

int	validate_accesibility(char **map, int height, int width)
{
	t_map_info	info;

	info.reach_exits = 0;
	info.reach_collectibles = 0;
	find_start_position(map, height, width, &info);
	if (!check_start_position(&info))
		return (0);
	flood_fill(map, info.start_x, info.start_y, &info);
	return (check_accessibility(&info));
}
