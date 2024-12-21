/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:57:48 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/21 19:59:24 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdio.h>

void	record_door_position(char **tab, ssize_t *door_y, ssize_t *door_x)
{
	static int	door_updated = 0;

	if (!door_updated && !has_edibles(tab))
	{
		*door_y = find_character_y(tab, 'd');
		*door_x = find_character_x(tab, 'd');
		if (*door_y != -1 && *door_x != -1)
		{
			tab[*door_y][*door_x] = 'D';
			door_updated = 1;
		}
	}
}

void	update_door(char **tab)
{
	static int	door_updated = 0;
	ssize_t		door_y;
	ssize_t		door_x;

	if (!door_updated && !has_edibles(tab))
	{
		door_y = find_character_y(tab, 'd');
		door_x = find_character_x(tab, 'd');
		if (door_y != -1 && door_x != -1)
		{
			tab[door_y][door_x] = 'D';
			door_updated = 1;
		}
	}
}
int	is_character_on_door(char **tab, ssize_t door_y, ssize_t door_x)
{
	ssize_t	char_y;
	ssize_t	char_x;

	char_y = find_character_y(tab, 'c');
	char_x = find_character_x(tab, 'c');
	if (char_y == door_y && char_x == door_x)
	{
		return (1); // Le personnage est sur la porte
	}
	return (0); // Le personnage n'est pas sur la porte
}

void	game_loop(char **tab, int fd)
{
	char	c;
	ssize_t	door_y;
	ssize_t	door_x;

	door_y = -1;
	door_x = -1;
	while (1)
	{
		record_door_position(tab, &door_y, &door_x);
		ft_print_tab(tab);
		printf("Press w a s d to move\n");
		if (my_scanf(" %c", &c) != 1)
		{
			perror("Error reading input");
			free_tab(tab);
			close(fd);
			exit(1);
		}
		check_specifier(tab, c);
		if (is_character_on_door(tab, door_y, door_x))
		{
			printf("You have reached the door! You win!\n");
			break ;
		}
	}
}
