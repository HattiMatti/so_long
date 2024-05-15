/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:48:07 by msiitone          #+#    #+#             */
/*   Updated: 2024/05/15 14:37:14 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start >= len)
		return (ft_gnl_strdup(""));
	if (len > (len - start))
		len = (len - start);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start] && len > 0)
	{
		sub[i] = s[start];
		i++;
		start++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	j = -1;
	i = -1;
	k = 0;
	l = 0;
	while (s1[k])
		k++;
	while (s2[l])
		l++;
	jstr = (char *)malloc(sizeof(char) * (k + l + 1));
	if (jstr == NULL)
		return (NULL);
	while (s1[++i])
		jstr[i] = s1[i];
	while (s2[++j])
		jstr[i + j] = s2[j];
	jstr[i + j] = '\0';
	return (jstr);
}

char	*ft_gnl_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	dest = (char *) malloc(i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_gnl_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

int	ft_nl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
