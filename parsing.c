/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:04:48 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/21 18:59:20 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

ssize_t	find_door(char **tab, char target)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == target)
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

ssize_t	find_character_x(char **tab, char target)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == target)
			{
				return (x);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

ssize_t	find_character_y(char **tab, char target)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == target)
			{
				return (y);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

bool	has_edibles(char **tab)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == 'e')
			{
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

ssize_t	my_scanf(const char *format, void *var)
{
	char	buffer[100];

	if (read(0, buffer, 100) == -1)
		return (-1);
	return (sscanf(buffer, format, var));
}
