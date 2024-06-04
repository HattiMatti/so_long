/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:26:19 by msiitone          #+#    #+#             */
/*   Updated: 2024/06/03 16:27:13 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_map(t_struct *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				map->x = j;
				map->y = i;
				map->player++;
			}
			else if (map->map[i][j] == 'C')
				map->collectible++;
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0')
				erfre(map, 6);
			j++;
		}
		i++;
	}
}

int	validate_counts(t_struct *map)
{
	if (map->player == 1 && map->exit == 1 && map->collectible >= 1)
		return (0);
	else
	{
		free_map(map, 2);
		erfre(map, 5);
		return (1);
	}
}

void	get_paid(t_struct *map)
{
	int	i;

	i = 0;
	if (map->map[map->y][map->x] == 'C')
	{
		while(map->collectible > 0)
		{
		}
	}
}
