/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:28:48 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/26 16:34:22 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_textures(t_struct *map)
{
	if (map->floor_texture)
	{
		mlx_delete_texture(map->floor_texture);
		map->floor_texture = NULL;
	}
	if (map->wall_texture)
	{
		mlx_delete_texture(map->wall_texture);
		map->wall_texture = NULL;
	}
	if (map->collectible_texture)
	{
		mlx_delete_texture(map->collectible_texture);
		map->collectible_texture = NULL;
	}
	if (map->player_texture)
	{
		mlx_delete_texture(map->player_texture);
		map->player_texture = NULL;
	}
	if (map->exit_texture)
	{
		mlx_delete_texture(map->exit_texture);
		map->exit_texture = NULL;
	}
}

void	free_images(t_struct *map)
{
	if (map->floor_img)
	{
		mlx_delete_image(map->mlx, map->floor_img);
		map->floor_img = NULL;
	}
	if (map->wall_img)
	{
		mlx_delete_image(map->mlx, map->wall_img);
		map->wall_img = NULL;
	}
	if (map->collectible_img)
	{
		mlx_delete_image(map->mlx, map->collectible_img);
		map->collectible_img = NULL;
	}
	if (map->player_img)
	{
		mlx_delete_image(map->mlx, map->player_img);
		map->player_img = NULL;
	}
	if (map->exit_img)
	{
		mlx_delete_image(map->mlx, map->exit_img);
		map->exit_img = NULL;
	}
}

void	free_map(t_struct *map, int flag)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		if (flag == 2)
			map->lines = map->map_height;
		while (map->map[i] != NULL && i < map->lines)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}

void	erfre(t_struct *map, int flag)
{
	free_map(map, 1);
	free_images(map);
	free_textures(map);
	if (flag == 1)
		ft_putstr_fd("Error: error opening map\n", 2);
	else if (map->map_height == 0)
		ft_putstr_fd("Error: map not valid\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Error: incorrect walls\n", 2);
	else if (flag == 3)
		ft_putstr_fd("Error: error allocating map\n", 2);
	else if (flag == 4)
		ft_putstr_fd("Error: MLX\n", 2);
	exit(EXIT_FAILURE);
}
