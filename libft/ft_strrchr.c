/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:15:33 by msiitone          #+#    #+#             */
/*   Updated: 2023/11/01 22:29:39 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	p;

	p = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == p)
			return ((char *)s + i);
		i--;
	}
	if (p == '\0')
		return ((char *)s + i);
	return (NULL);
}
