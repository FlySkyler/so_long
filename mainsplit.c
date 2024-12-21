/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:43:28 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/21 19:58:26 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"
#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

char	**load_map(int fd, size_t lines)
{
	char	**tab;

	tab = mapping(fd, lines);
	if (!tab)
	{
		perror("Error mapping file");
		close(fd);
	}
	return (tab);
}

ssize_t	process_lines(char **tab, size_t lines)
{
	int	y;
	int	count;
	int	x;

	y = 0;
	count = 0;
	while (tab[y] != 0)
	{
		tab[y] = extract_substring(tab[y]);
		tab[y] = check_invalid(tab[y]);
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == '1')
				count++;
			x++;
		}
		if ((y > 0 && y < lines - 1) && count != 2)
			return (-1);
		count = 0;
		y++;
	}
	return (0);
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int	validate_map(char **tab, size_t lines, int fd)
{
	if (process_lines(tab, lines) + check_mapping(tab, lines) < 0)
	{
		perror("Error invalid map");
		free_tab(tab);
		close(fd);
		return (1);
	}
	return (0);
}

