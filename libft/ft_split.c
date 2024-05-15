/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:37:34 by msiitone          #+#    #+#             */
/*   Updated: 2024/03/27 17:52:52 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_skip(char *str, char c, int *pos)
{
	int	len;

	len = 0;
	while (str[*pos] == c)
		(*pos)++;
	while (str[*pos] && str[*pos] != c)
	{
		len++;
		(*pos)++;
	}
	return (len);
}

static char	*ft_word(char *str, char c, int *pos)
{
	char	*word;
	int		j;
	int		len;
	int		i;

	j = *pos;
	len = ft_skip(str, c, pos);
	word = (char *) malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (str[j] != c)
		{
			word[i] = str[j];
			i++;
		}
		j++;
	}
	(*pos)++;
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		pos;

	if (s == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_count((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (arr == NULL)
		return (NULL);
	while (i < j)
	{
		arr[i] = ft_word((char *)s, c, &pos);
		if (arr[i] == NULL)
		{
			ft_free_split(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
