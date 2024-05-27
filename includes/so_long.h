/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:33:25 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/22 16:37:52 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

typedef struct s_struct
{
	int	map_width;
	int	map_height;
}	t_struct;

int		check_walls(char *map_name, t_struct *map);
int		check_map_name(char *map_name);
int		check_map(char *map_name, t_struct *map);
int		llen_match(char *line, int len);
void	erfre(t_struct *map, int flag);



#endif
