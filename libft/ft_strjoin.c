/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:53:48 by msiitone          #+#    #+#             */
/*   Updated: 2023/11/17 01:17:22 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	jstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (jstr == NULL)
		return (NULL);
	while (s1[i])
	{
		jstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		jstr[i + j] = s2[j];
		j++;
	}
	jstr[i + j] = '\0';
	return (jstr);
}
