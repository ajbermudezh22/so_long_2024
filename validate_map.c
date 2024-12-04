/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:14:59 by albermud          #+#    #+#             */
/*   Updated: 2024/12/04 09:28:34 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_rectangular(char **map, int height)
{
	int	width;
	int	i;

	i = 1;
	width = ft_strlen(map[0]);
	while (i < height)
	{
		if ((int)ft_strlen(map[i]) != width)
		{
			ft_printf("Error\nMap is not rectangular");
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

	i = 0;
	width = ft_strlen(map[0]);
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
		{
			ft_printf("Error\nMap is not enclosed by walls");
			return (0);
		}
		i++;
	}
	i = 1;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
		{
			ft_printf("Error\nMap is not enclosed by walls");
			return (0);
		}
		i++;
	}
	return (1);
}

int	count_map_elements(char **map, int height, int *exit_count,
		int *start_count, int *collectible_count)
{
	int i;
	int j;

	i = 0;
	*exit_count = 0;
	*start_count = 0;
	*collectible_count = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				exit_count++;
			else if (map[i][j] == 'P')
				start_count++;
			else if (map[i][j] == 'C')
				collectible_count++;
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map_elements(char **map, int height)
{
	int	exit_count;
	int start_count;
	int collectible_count;

	count_map_elements(map, height, &exit_count, &start_count, &collectible_count);
    if (exit_count != 1)
    {
        ft_printf("Error\nMap must contain exactly one exit\n");
        return (0);
    }
    if (start_count != 1)
    {
        ft_printf("Error\nMap must contain exactly one start position\n");
        return (0);
    }
    if (collectible_count < 1)
    {
        ft_printf("Error\nMap must contain at least one collectible\n");
        return (0);
    }
    return (1);
}

void	validate_map(char **map, int height)
{
	int i;

	i = 0;
	if (!is_map_rectangular(map, height) || !is_map_enclosed(map, height)
		|| !validate_map_elements(map, height))
	{
		while (i < height)
		{
			free(map[i]);
			i++;
		}
		free(map);
		exit(EXIT_FAILURE);
	}
}
