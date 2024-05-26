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

void	erfre(t_struct *map, int flag)
{
	if (flag == 1)
		ft_putstr_fd("error opening map", 2);
	exit(EXIT_FAILURE);
}
