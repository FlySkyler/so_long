/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/11 19:16:21 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define INVALID "23456789abfghijklmnopqrstuvwxyzABCEFGHIJKLMNOPQRSTUVWXYZ "
# include "unistd.h"

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	void	*wall_img;
	void	*floor_img;
	int		img_width;
	int		img_height;
	void	*collectible_img;
	void	*character_img;
	int		collectibles_remaining;
	void	*door_closed;
	int		door_x;
	int		door_y;
	void	*door_open;
}			t_game;

char		**mapping(int fd, size_t lines);
char		*extract_substring(char *str);
char		*check_invalid(char *str);
ssize_t		check_mapping(char **tab, size_t lines);
void		free_tab(char **tab);
int			validate_map(char **tab, size_t lines, int fd);
char		**load_map(int fd, size_t lines);
ssize_t		process_lines(char **tab, size_t lines);
void		draw_map(t_game *game);
int			handle_keypress(int keysym, t_game *game);
int			init_textures(t_game *game);
void		cleanup_textures(t_game *game);
void		init_collectibles(t_game *game);
int			init_window_and_textures(t_game *game);
int			init_game(t_game *game, const char *filename);
int         open_file(const char *filename);
ssize_t     count_lines(const char *filename);

#endif