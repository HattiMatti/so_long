/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:24:58 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/24 23:49:52 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	llen_match(char *line, int len)
{
	if ((int)ft_strlen(line) == len)
		return (len);
	else
	{
		ft_putstr_fd("Error: Map is not rectangle\n", 2);
		return (-1);
	}
}

int	check_map(char *map_name, t_struct *map)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		erfre(map, 1);
	line = get_next_line(fd);
	map->map_height = 0;
	map->map_width = ft_strlen(line);
	while (line != NULL)
	{
		map->map_width = llen_match(line, map->map_width);
		if (map->map_width == -1)
		{
			free(line);
			close(fd);
			erfre(map, 0);
		}
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
		map->map_height++;
	}
	close(fd);
	return (0);
}
