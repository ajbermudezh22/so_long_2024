/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:14:59 by albermud          #+#    #+#             */
/*   Updated: 2025/01/07 10:12:32 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_rectangular(char **map, int height)
{
	int	width;
	int	i;

	width = ft_strlen(map[0]);
	i = 1;
	while (i < height)
	{
		if ((int)ft_strlen(map[i]) != width)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_map_enclosed(char **map, int height)
{
	int	width;
	int	i;

	width = ft_strlen(map[0]);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_map_elements(char **map, int height, t_map_elements *elements)
{
	int	i;
	int	j;

	elements->exit_count = 0;
	elements->start_count = 0;
	elements->collectible_count = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				elements->exit_count++;
			else if (map[i][j] == 'P')
				elements->start_count++;
			else if (map[i][j] == 'C')
				elements->collectible_count++;
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map_elements(char **map, int height)
{
	t_map_elements	elements;

	count_map_elements(map, height, &elements);
	if (elements.exit_count != 1)
	{
		ft_printf("Error\nMap must have exactly one exit\n");
		return (0);
	}
	if (elements.start_count != 1)
	{
		ft_printf("Error\nMap must have exactly one starting point\n");
		return (0);
	}
	if (elements.collectible_count < 1)
	{
		ft_printf("Error\nMap must have at least one collectible\n");
		return (0);
	}
	return (1);
}

void	validate_map(char **map, int height)
{
	if (!is_map_rectangular(map, height) || !is_map_enclosed(map, height)
		|| !validate_map_elements(map, height))
	{
		ft_printf("Error\nInvalid map\n");
		exit(EXIT_FAILURE);
	}
}
