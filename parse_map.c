/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:36:27 by albermud          #+#    #+#             */
/*   Updated: 2024/11/27 20:45:03 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map_file(const char *filename, int *height)
{
	int fd;
	int line_count;
	char	**map;
	char	*line;

	fd = open_map_file(filename);
	line_count = 0;
	map = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		map = resize_map_mem(map, line_count);
		map[line_count++] = line;
	}
	close(fd);
	check_empty_map(line_count, map);
	map[line_count] = NULL;
	*height = line_count;
	return (map);
}

void	parse_map(t_game *game, const char *filename)
{
	game->map = read_map_file(filename, &game->map_height);
	game->map_width = ft_strlen(game->map[0]);
	validate_map(game->map, game->map_height);
}
