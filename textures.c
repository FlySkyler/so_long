/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:00:01 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/11 19:02:06 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx-linux/mlx.h"

int	init_textures(t_game *game)
{
	game->img_width = 40;
	game->img_height = 40;
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/wall.xpm",
			&game->img_width, &game->img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/floor.xpm",
			&game->img_width, &game->img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/collectible.xpm", &game->img_width, &game->img_height);
	game->character_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/character.xpm", &game->img_width, &game->img_height);
	game->door_closed = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/closed_door.xpm", &game->img_width, &game->img_height);
	game->door_open = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/open_tunnel.xpm", &game->img_width, &game->img_height);
	if (!game->collectible_img || !game->character_img || !game->wall_img
		|| !game->floor_img || !game->door_closed || !game->door_open)
		return (0);
	return (1);
}

void	cleanup_textures(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	if (game->character_img)
		mlx_destroy_image(game->mlx_ptr, game->character_img);
	if (game->door_closed)
		mlx_destroy_image(game->mlx_ptr, game->door_closed);
	if (game->door_open)
		mlx_destroy_image(game->mlx_ptr, game->door_open);
}
