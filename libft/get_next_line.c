/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:55:33 by msiitone          #+#    #+#             */
/*   Updated: 2024/03/28 14:56:05 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_temp(char *temp, char *buf)
{
	char	*line;
	char	*filler;

	if (!temp && buf)
	{
		line = ft_gnl_strdup(buf);
		if (!line)
			return (ft_gnl_free(&line));
		return (line);
	}
	filler = ft_gnl_strdup(temp);
	if (!filler)
	{
		ft_gnl_free(&temp);
		return (ft_gnl_free(&filler));
	}
	ft_gnl_free(&temp);
	line = ft_gnl_strjoin(filler, buf);
	if (!line)
		ft_gnl_free(&line);
	ft_gnl_free(&filler);
	return (line);
}

static char	*ft_extract(char *temp)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!temp)
		return (ft_gnl_free(&temp));
	while (temp[i] != '\n')
		i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_gnl_free(&line));
	while (j < i + 1)
	{
		line[j] = temp[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_rest(char *temp)
{
	size_t	i;
	size_t	j;
	char	*rest;

	j = 0;
	i = 0;
	if (!temp)
		return (NULL);
	while (temp[j])
		j++;
	while (temp[i] != '\n')
		i++;
	if (!(temp[i] + 1))
		return (ft_gnl_free(&temp));
	rest = ft_gnl_substr(temp, i + 1, j);
	if (!rest)
		return (ft_gnl_free(&temp));
	ft_gnl_free(&temp);
	return (rest);
}

static char	*ft_final(char **temp)
{
	char	*final;

	if (*temp && **temp)
	{
		final = ft_gnl_strdup(*temp);
		ft_gnl_free(temp);
		return (final);
	}
	ft_gnl_free(temp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			read_size;

	line = NULL;
	read_size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_gnl_free(&temp));
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if ((read_size <= 0 && !temp) || read_size == -1)
			return (ft_gnl_free(&temp));
		buf[read_size] = '\0';
		temp = ft_fill_temp(temp, buf);
		if (ft_nl(temp))
		{
			line = ft_extract(temp);
			if (!line)
				return (ft_gnl_free(&temp));
			return (temp = ft_rest(temp), line);
		}
	}
	return (ft_final(&temp));
}
