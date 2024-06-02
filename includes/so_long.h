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
	int				map_width;
	int				map_height;
	int				lines;
	int				x;
	int				y;
	char			**map;
	mlx_t			*mlx;
	mlx_image_t		*floor_img;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*exit_texture;
}	t_struct;

int		check_walls(char *line, t_struct *map, int flag);
int		map_line_read(char *map_name, t_struct *map);
int		check_map_name(char *map_name);
int		check_map(char *map_name, t_struct *map);
int		llen_match(char *line, int len);
void	erfre(t_struct *map, int flag);
void	free_map(t_struct *map, int flag);
void	texture_to_img(t_struct	*map);



#endif
