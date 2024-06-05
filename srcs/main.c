/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:30:13 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/21 15:30:30 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_counter(t_struct *map, int key)
{
	if (key == 1 && map->map[map->y - 1][map->x] != '1')
	{
		ft_printf("number of movements: %d\n", map->moves++);
		map->y -= 1;
		map->player_img->instances[0].y -= 50;
	}
	if (key == 2 && map->map[map->y][map->x - 1] != '1')
	{
		ft_printf("number of movements: %d\n", map->moves++);
		map->x -= 1;
		map->player_img->instances[0].x -= 50;
	}
	if (key == 3 && map->map[map->y + 1][map->x] != '1')
	{
		ft_printf("number of movements: %d\n", map->moves++);
		map->y += 1;
		map->player_img->instances[0].y += 50;
	}
	if (key == 4 && map->map[map->y][map->x + 1] != '1')
	{
		ft_printf("number of movements: %d\n", map->moves++);
		map->x += 1;
		map->player_img->instances[0].x += 50;
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_struct	*map;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		move_counter(map, 1);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		move_counter(map, 2);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		move_counter(map, 3);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		move_counter(map, 4);
	}
	get_paid(map);
	win_if_collected(map);
}

void	init_window(t_struct *map)
{
	int	width;
	int	height;
	int	scr_width;
	int	scr_height;

	width = 50 * (map->map_width - 1);
	height = 50 * map->map_height;
	map->mlx = mlx_init(width, height, "so_long", false);
	if (!map->mlx)
		erfre(map, 4);
	mlx_get_monitor_size(0, &scr_width, &scr_height);
	if (scr_width < width || scr_height < height)
		erfre(map, 8);
	load_textures(map);
	texture_to_img(map);
	draw_floor(map);
	draw_walls(map);
	map->moves = 1;
	mlx_key_hook(map->mlx, my_key_hook, map);
	mlx_loop(map->mlx);
}

int	map_fuctions(char *map_name, t_struct *map)
{
	check_map_name(map_name);
	check_map(map_name, map);
	map->map = malloc((map->map_height + 1) * sizeof(char *));
	if (map->map == NULL)
		erfre(map, 3);
	map_line_read(map_name, map);
	validate_map(map);
	validate_counts(map);
	init_visited(map);
	floodfill(map, map->y, map->x);
	check_visited(map);
	return (0);
}

int	main(int argc, char **argv)
{
	char		*map_name;
	t_struct	map;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n Wrong number of arguments\n", 2);
		return (0);
	}
	ft_memset(&map, 0, sizeof(map));
	map_name = argv[1];
	map_fuctions(map_name, &map);
	init_window(&map);
	if (map.map != NULL)
		free_map(&map, 2);
	free_textures(&map);
	free_images(&map);
	free_flood(&map);
	mlx_terminate(map.mlx);
	return (0);
}
