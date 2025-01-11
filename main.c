/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:20:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/11 19:19:00 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"
#include "./minilibx-linux/mlx.h"
#include "so_long.h"
#include <X11/keysym.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	t_game	game;

	if (init_game(&game, "./map/map.txt") != 0)
		return (1);
	mlx_key_hook(game.win_ptr, handle_keypress, &game);
	init_collectibles(&game);
	draw_map(&game);
	mlx_loop(game.mlx_ptr);
	free_tab(game.map);
	cleanup_textures(&game);
	close(open_file("./map/map.txt"));
	return (0);
}
