/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:47:34 by msiitone          #+#    #+#             */
/*   Updated: 2024/06/02 18:48:00 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_floor(t_struct *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < (map->map_width - 1))
		{
			if (mlx_image_to_window(map->mlx, map->floor_img
					, 50 * x, 50 * y) < 0)
				erfre(map, 4);
			if (map->map[y][x] == 'E')
				if (mlx_image_to_window(map->mlx, map->exit_img
						, 50 * x, 50 * y) < 0)
					erfre(map, 4);
			if (map->map[y][x] == 'C')
				if (mlx_image_to_window(map->mlx, map->collectible_img
						, 50 * x, 50 * y) < 0)
					erfre(map, 4);
			x++;
		}
		y++;
	}
}

void	draw_walls(t_struct *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < (map->map_width - 1))
		{
			if (map->map[y][x] == '1')
				if (mlx_image_to_window(map->mlx, map->wall_img
						, 50 * x, 50 * y) < 0)
					erfre(map, 4);
			if (map->map[y][x] == 'P')
				if (mlx_image_to_window(map->mlx, map->player_img
						, 50 * x, 50 * y) < 0)
					erfre(map, 4);

			x++;
		}
		y++;
	}
}

void	load_textures(t_struct *map)
{
	map->floor_texture = mlx_load_png("textures/floor.png");
	if (!map->floor_texture)
		erfre(map, 4);
	map->wall_texture = mlx_load_png("textures/wall.png");
	if (!map->wall_texture)
		erfre(map, 4);
	map->collectible_texture = mlx_load_png("textures/collectible.png");
	if (!map->collectible_texture)
		erfre(map, 4);
	map->player_texture = mlx_load_png("textures/player.png");
	if (!map->player_texture)
		erfre(map, 4);
	map->exit_texture = mlx_load_png("textures/exit.png");
	if (!map->exit_texture)
		erfre(map, 4);
}

void	texture_to_img(t_struct	*map)
{
	map->floor_img = mlx_texture_to_image(map->mlx, map->floor_texture);
	if (!map->floor_img)
		erfre(map, 4);
	map->wall_img = mlx_texture_to_image(map->mlx, map->wall_texture);
	if (!map->wall_img)
		erfre(map, 4);
	map->player_img = mlx_texture_to_image(map->mlx, map->player_texture);
	if (!map->player_img)
		erfre(map, 4);
	map->collectible_img = mlx_texture_to_image(map->mlx,
			map->collectible_texture);
	if (!map->collectible_img)
		erfre(map, 4);
	map->exit_img = mlx_texture_to_image(map->mlx, map->exit_texture);
	if (!map->exit_img)
		erfre(map, 4);
}
