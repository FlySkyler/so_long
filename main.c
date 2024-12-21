/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:20:15 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/21 19:10:28 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int	main(void)
{
	size_t	lines;
	int		fd;
	char	**tab;

	lines = count_lines("./map txt/map.txt");
	fd = open_file("./map txt/map.txt");
	if (fd == -1)
		return (-1);
	tab = load_map(fd, lines);
	if (!tab)
		return (1);
	if (validate_map(tab, lines, fd) != 0)
		return (1);
	game_loop(tab, fd);
	free_tab(tab);
	close(fd);
	return (0);
}
