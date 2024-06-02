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
	map->collectible_img = mlx_texture_to_image(map->mlx, map->player_texture);
	if (!map->collectible_img)
		erfre(map, 4);
	map->exit_img = mlx_texture_to_image(map->mlx, map->exit_texture);
	if (!map->exit_img)
		erfre(map, 4);
	if (mlx_image_to_window(map->mlx, map->floor_img, 0, 0) < 0)
		erfre(map, 4);
}
