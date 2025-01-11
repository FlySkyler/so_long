/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:57:51 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/11 19:08:26 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "so_long.h"
#include <X11/keysym.h>
#include <stdlib.h>

void	move_player(int keysym, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->player_x;
	old_y = game->player_y;
	if (keysym == XK_w || keysym == XK_Up)
		game->player_y--;
	if (keysym == XK_s || keysym == XK_Down)
		game->player_y++;
	if (keysym == XK_a || keysym == XK_Left)
		game->player_x--;
	if (keysym == XK_d || keysym == XK_Right)
		game->player_x++;
	if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'd')
	{
		game->player_x = old_x;
		game->player_y = old_y;
	}
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		free_tab(game->map);
		exit(0);
	}
	move_player(keysym, game);
	if (game->map[game->player_y][game->player_x] == 'e')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->collectibles_remaining--;
	}
	if (game->collectibles_remaining == 0)
		game->map[game->door_y][game->door_x] = 'D';
	if (game->map[game->player_y][game->player_x] == 'D')
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		free_tab(game->map);
		exit(0);
	}
	return (draw_map(game), 0);
}
