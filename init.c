/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:11:52 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/11 19:19:16 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minilibx-linux/mlx.h"
#include "so_long.h"
#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"

ssize_t	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	size_t	lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (lines == 0)
	{
		perror("Error reading file");
		return (-1);
	}
	return (lines);
}

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
	}
	return (fd);
}

void	init_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->collectibles_remaining = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'e')
				game->collectibles_remaining++;
			else if (game->map[y][x] == 'd')
			{
				game->door_x = x;
				game->door_y = y;
			}
			x++;
		}
		y++;
	}
}

int	init_window_and_textures(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	if (!init_textures(game))
	{
		perror("Error loading textures\n");
		return (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width * 40,
			game->map_height * 40, "Map Window");
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		return (1);
	}
	return (0);
}

int	init_game(t_game *game, const char *filename)
{
	int	fd;

	fd = open_file(filename);
	if (fd == -1)
		return (-1);
	game->map = load_map(fd, count_lines(filename));
	if (!game->map)
		return (1);
	if (validate_map(game->map, count_lines(filename), fd) != 0)
		return (1);
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = count_lines(filename);
	game->player_x = 1;
	game->player_y = 1;
	if (init_window_and_textures(game) != 0)
		return (1);
	return (0);
}
