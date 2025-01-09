/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:36:27 by albermud          #+#    #+#             */
/*   Updated: 2025/01/07 10:05:19 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map_file(const char *filename, int *height)
{
	int		fd;
	int		line_count;
	char	**map;
	char	*line;
	char	*trimmed_line;

	fd = open_map_file(filename);
	line_count = 0;
	map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed_line = ft_strtrim(line, "\n");
		free(line);
		map = resize_map_mem(map, line_count);
		map[line_count++] = trimmed_line;
		line = get_next_line(fd);
	}
	close(fd);
	check_empty_map(line_count, map);
	map[line_count] = NULL;
	*height = line_count;
	return (map);
}

static int	count_total_collectibles(char **map, int height)
{
	int	total;
	int	y;
	int	x;

	total = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				total++;
			x++;
		}
		y++;
	}
	return (total);
}

static void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	map_error("Error: No player position found in the map");
}

void	parse_map(t_game *game, const char *filename)
{
	ft_printf("Parsing map from file: %s\n", filename);
	game->map = read_map_file(filename, &game->map_height);
	game->map_width = ft_strlen(game->map[0]);
	validate_map(game->map, game->map_height);
	game->collectibles = count_total_collectibles(game->map, game->map_height);
	find_player_position(game);
}
