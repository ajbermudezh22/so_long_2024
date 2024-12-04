/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:43:41 by albbermu          #+#    #+#             */
/*   Updated: 2024/12/04 09:24:55 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(1);
}

void load_textures(t_game *game, t_texture *textures)
{
    int width;
    int height;

    textures->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &width, &height);
    if (!textures->wall)
        exit(EXIT_FAILURE);
    textures->floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &width, &height);
    textures->collectible = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &width, &height);
    textures->exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &width, &height);
    textures->player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &width, &height);
    if (!textures->floor || !textures->collectible || !textures->exit || !textures->player)
        exit(EXIT_FAILURE);
}

int	open_map_file(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char **resize_map_mem(char **map, int line_count)
{
	char	**temp_map;
	
	temp_map = realloc(map, (line_count + 2) * sizeof(char *));
	if (!temp_map)
	{
		perror("Error reallocating memory for map");
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
