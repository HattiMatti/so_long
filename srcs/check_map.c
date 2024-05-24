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

int	check_map(char *map_name)
{
	int		line_count;
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit(0);
	line_count = 0;
	line = get_next_line(fd);
	ft_strlen(line);
	while (line != NULL)
	{
		ft_printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	close(fd);
	return (0);
}
