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
			ft_printf("hereree\n");
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
	if (flag == 1)
		ft_putstr_fd("Error: error opening map\n", 2);
	else if (map->map_height == 0)
		ft_putstr_fd("Error: map not valid\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Error: incorrect walls\n", 2);
	else if (flag == 3)
		ft_putstr_fd("Error: error allocating map\n", 2);
	exit(EXIT_FAILURE);
}
