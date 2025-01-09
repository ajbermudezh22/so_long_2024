/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:43:41 by albbermu          #+#    #+#             */
/*   Updated: 2025/01/07 09:49:47 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game, t_texture *textures)
{
	int	width;
	int	height;

	textures->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&width, &height);
	if (!textures->wall)
		map_error("Error loading texture: wall.xpm");
	textures->floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&width, &height);
	if (!textures->floor)
		map_error("Error loading texture: floor.xpm");
	textures->collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &width, &height);
	if (!textures->collectible)
		map_error("Error loading texture: collectible.xpm");
	textures->exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&width, &height);
	if (!textures->exit)
		map_error("Error loading texture: exit.xpm");
	textures->player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			&width, &height);
	if (!textures->player)
		map_error("Error loading texture: player.xpm");
}

void	map_error(char *s)
{
	ft_printf("Error\n%s\n", s);
	exit(EXIT_FAILURE);
}

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	**resize_map_mem(char **map, int line_count)
{
	char	**temp_map;

	temp_map = realloc(map, (line_count + 2) * sizeof(char *));
	if (!temp_map)
	{
		perror("Error reallocating memory");
		free(map);
		exit(EXIT_FAILURE);
	}
	return (temp_map);
}

void	check_empty_map(int line_count, char **map)
{
	if (line_count == 0)
	{
		ft_printf("Error\nMap is empty\n");
		free(map);
		exit(EXIT_FAILURE);
	}
}
