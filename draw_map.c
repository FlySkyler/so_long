/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:55:59 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/11 19:05:31 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "so_long.h"

void	draw_cell(t_game *game, int x, int y, int cell_size)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_img, x
		* cell_size, y * cell_size);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_img, x
			* cell_size, y * cell_size);
	else if (game->map[y][x] == 'e')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collectible_img, x * cell_size, y * cell_size);
	else if (game->map[y][x] == 'd')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->door_closed,
			x * cell_size, y * cell_size);
	else if (game->map[y][x] == 'D')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->door_open, x
			* cell_size, y * cell_size);
}

void	draw_map(t_game *game)
{
	int	cell_size;
	int	x;
	int	y;

	cell_size = 40;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_cell(game, x, y, cell_size);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->character_img,
		game->player_x * cell_size, game->player_y * cell_size);
}
