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
	check_map_name(map_name);
	check_map(map_name, &map);
	ft_printf("width: %d height: %d\n", map.map_width, map.map_height);
	return (0);
}
