/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:43:16 by msiitone          #+#    #+#             */
/*   Updated: 2024/06/03 13:44:22 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_visited(t_struct *map, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (map->visited[i] != NULL)
			free(map->visited[i]);
		i++;
	}
	free(map->visited);
}

void	init_visited(t_struct *map)
{
	int	i;
	int	j;

	i = 0;
	map->visited = malloc(map->map_height * sizeof(char *));
	if (map->visited == NULL)
		erfre(map, 2);
	while (i < map->map_height)
	{
		map->visited[i] = malloc((map->map_width + 1) * sizeof(char));
		if (map->visited[i] == NULL)
		{
			free_visited(map, i);
			erfre(map, 2);
		}
		j = 0;
		while (j < map->map_width)
		{
			map->visited[i][j] = '0';
			j++;
		}
		map->visited[i][j] = '\0';
		i++;
	}
}

void	floodfill(t_struct *map, int y, int x)
{
	int	width;

	width = map->map_width - 1;
	if (y < 0 || y >= map->map_height || x < 0 || x >= width
		|| map->visited[y][x] == '1')
		return ;
	map->visited[y][x] = '1';
	if (map->map[y][x + 1] == '0' || map->map[y][x + 1] == 'C'
		|| map->map[y][x + 1] == 'E')
		floodfill(map, y, x + 1);
	if (map->map[y][x - 1] == '0' || map->map[y][x - 1] == 'C'
		|| map->map[y][x - 1] == 'E')
		floodfill(map, y, x - 1);
	if (map->map[y + 1][x] == '0' || map->map[y + 1][x] == 'C'
		|| map->map[y + 1][x] == 'E')
		floodfill(map, y + 1, x);
	if (map->map[y - 1][x] == '0' || map->map[y - 1][x] == 'C'
		|| map->map[y - 1][x] == 'E')
		floodfill(map, y - 1, x);
}

void	check_visited(t_struct *map)
{
	int	x;
	int	y;
	int	collectible;
	int	exit;

	y = 0;
	exit = 1;
	collectible = map->collectible;
	while (y < map->map_height)
	{
		x = 0;
		while (x < (map->map_width - 1))
		{
			if (map->map[y][x] == 'C' && map->visited[y][x] == '1')
				collectible--;
			else if (map->map[y][x] == 'E' && map->visited[y][x] == '1')
				exit--;
			x++;
		}
		y++;
	}
	if (collectible != 0 || exit != 0)
		erfre(map, 7);
}
