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
	
}
void	texture_to_img(t_struct	*map)
{

	map->floor_img = mlx_texture_to_image(map->mlx, map->floor_texture);
	if (!map->floor_img)
		erfre(map, 4);
	if (mlx_image_to_window(map->mlx, map->floor_img, 50, 50) < 0)
		erfre(map, 4);
}
