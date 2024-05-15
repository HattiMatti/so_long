/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:57:50 by msiitone          #+#    #+#             */
/*   Updated: 2023/11/17 01:16:59 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	p;
	char	*str;

	i = 0;
	p = (char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == p)
			return (&str[i]);
		i++;
	}
	if (p == '\0')
		return (&str[i]);
	return (0);
}
