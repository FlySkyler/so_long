/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:35:36 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/11 18:49:05 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include "stdio.h"

char	*extract_substring(char *str)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*substring;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && str[start] != '1')
		start++;
	while (end > start && str[end] != '1')
		end--;
	if (str[start] != '1' || str[end] != '1')
		return (NULL);
	len = end - start + 2;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, str + start, len);
	substring[len] = '\0';
	free(str);
	return (substring);
}

char	*check_invalid(char *str)
{
	size_t	len;
	char	*filtered_str;
	size_t	j;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	filtered_str = (char *)malloc(len + 1);
	if (!filtered_str)
		return (NULL);
	j = 0;
	while (i < len)
	{
		if (!ft_strchr(INVALID, str[i]))
			filtered_str[j++] = str[i];
		i++;
	}
	filtered_str[j] = '\0';
	free(str);
	return (filtered_str);
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

ssize_t	check_mapping(char **tab, size_t lines)
{
	size_t	y;

	y = 0;
	while (tab[y] && y < lines)
	{
		if (ft_strlen(tab[0]) != ft_strlen(tab[y]))
			return (-1);
		else if ((tab[y][0] == 0 && tab[y][ft_strlen(tab[y])] == 0))
			return (-1);
		y++;
	}
	return (1);
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
