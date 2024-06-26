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
		ft_putstr_fd("Error\n Map is not rectangle\n", 2);
		return (-1);
	}
}

int	check_map_name(char *map_name)
{
	int		len;
	char	ber[5];

	ft_strlcpy(ber, ".ber", 5);
	len = ft_strlen(map_name);
	if (len > 4 && ft_strncmp(map_name + len - 4, ber, 4) == 0)
		return (0);
	else
	{
		ft_putstr_fd("Error\n incorrect map name\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	check_walls(char *line, t_struct *map, int flag)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0' && flag == 1)
	{
		if (line[i] != '1')
		{
			ft_putstr_fd("Error\n incorrect walls\n", 2);
			free_map(map, 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (flag == 2)
	{
		if (line[0] != '1' || line[len - 2] != '1')
		{
			ft_putstr_fd("Error\n incorrect walls\n", 2);
			free_map(map, 1);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

int	map_line_read(char *map_name, t_struct *map)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		erfre(map, 1);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map->lines = i;
		map->map[i] = line;
		if (i == 0 || i == map->map_height - 1)
			check_walls(line, map, 1);
		else
			check_walls(line, map, 2);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}

int	check_map(char *map_name, t_struct *map)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		erfre(map, 1);
	line = get_next_line(fd);
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
		free(line);
		line = get_next_line(fd);
		map->map_height++;
	}
	close(fd);
	return (0);
}
