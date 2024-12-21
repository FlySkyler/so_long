/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkspecifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:01:33 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/21 18:58:07 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

ssize_t	map_w(char **tab, ssize_t y, ssize_t x)
{
	if (tab[y - 1][x] != '1' && tab[y - 1][x] != 'd')
	{
		tab[y - 1][x] = 'c';
		tab[y][x] = '0';
		return (0);
	}
	return (-1);
}

ssize_t	map_a(char **tab, ssize_t y, ssize_t x)
{
	if (tab[y][x - 1] != '1' && tab[y][x - 1] != 'd')
	{
		tab[y][x - 1] = 'c';
		tab[y][x] = '0';
		return (0);
	}
	return (-1);
}

ssize_t	map_s(char **tab, ssize_t y, ssize_t x)
{
	if (tab[y + 1][x] != '1' && tab[y + 1][x] != 'd')
	{
		tab[y + 1][x] = 'c';
		tab[y][x] = '0';
		return (0);
	}
	return (-1);
}

ssize_t	map_d(char **tab, ssize_t y, ssize_t x)
{
	if (tab[y][x + 1] != '1' && tab[y][x + 1] != 'd')
	{
		tab[y][x + 1] = 'c';
		tab[y][x] = '0';
		return (0);
	}
	return (-1);
}

ssize_t	check_specifier(char **tab, char c)
{
	if (c == 'w')
		return (map_w(tab, find_character_y(tab, 'c'), find_character_x(tab,
					'c')));
	if (c == 'a')
		return (map_a(tab, find_character_y(tab, 'c'), find_character_x(tab,
					'c')));
	if (c == 's')
		return (map_s(tab, find_character_y(tab, 'c'), find_character_x(tab,
					'c')));
	if (c == 'd')
		return (map_d(tab, find_character_y(tab, 'c'), find_character_x(tab,
					'c')));
	return (-1);
}
