/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:10 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/21 19:59:02 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define INVALID "23456789abfghijklmnopqrstuvwxyzABCEFGHIJKLMNOPQRSTUVWXYZ "
# include <stdbool.h>
# include <stdlib.h>

char	**mapping(int fd, size_t lines);
char	*extract_substring(char *str);
char	*check_invalid(char *str);
ssize_t	check_mapping(char **tab, size_t lines);
void	free_tab(char **tab);
ssize_t	check_specifier(char **tab, char c);
ssize_t	mapW(char **tab, ssize_t y, ssize_t x);
ssize_t	mapA(char **tab, ssize_t y, ssize_t x);
ssize_t	mapS(char **tab, ssize_t y, ssize_t x);
ssize_t	mapD(char **tab, ssize_t y, ssize_t x);
ssize_t	find_character_x(char **tab, char target);
ssize_t	find_character_y(char **tab, char target);
bool	has_edibles(char **tab);
ssize_t	my_scanf(const char *format, void *var);
void	game_loop(char **tab, int fd);
int		validate_map(char **tab, size_t lines, int fd);
char	**load_map(int fd, size_t lines);
ssize_t	process_lines(char **tab, size_t lines);
void	ft_print_tab(char **tab);
ssize_t	find_door(char **tab, char target);
void    record_door_position(char **tab, ssize_t *door_y, ssize_t *door_x);
void    update_door(char **tab);
int     is_character_on_door(char **tab, ssize_t door_y, ssize_t door_x);

#endif