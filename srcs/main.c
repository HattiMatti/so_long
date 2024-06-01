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

int	map_fuctions(char *map_name, t_struct *map)
{
	int	i;

	i = 0;
	check_map_name(map_name);
	check_map(map_name, map);
	map->map = malloc((map->map_height + 1) * sizeof(char *));
	if (map->map == NULL)
		erfre(map, 3);
	map_line_read(map_name, map);
	while (i < map->map_height)
	{
		ft_printf("map: %s", map->map[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char		*map_name;
	t_struct	map;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (0);
	}
	ft_memset(&map, 0, sizeof(map));
	map_name = argv[1];
	map_fuctions(map_name, &map);
	ft_printf("width: %d height: %d\n", map.map_width, map.map_height);
	if (map.map != NULL)
		free_map(&map, 2);
	return (0);
}
