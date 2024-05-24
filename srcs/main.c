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
	char	*map_name;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments", 2);
		return (0);
	}
	map_name = argv[1];
	check_map(map_name);
	return (0);
}
