/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:22:10 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/18 16:44:08 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**mapping(int fd, size_t lines)
{
	char	**tab;
	char	*buffer;
	size_t	y;

	y = 0;
	if (fd < 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!tab)
		return (NULL);
	buffer = get_next_line(fd);
	while (buffer != NULL && y < lines)
	{
		tab[y] = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
		if (!tab[y])
			return (free(buffer), free_tab(tab), NULL);
		ft_strlcpy(tab[y], buffer, ft_strlen(buffer) + 1);
		free(buffer);
		buffer = get_next_line(fd);
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

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
