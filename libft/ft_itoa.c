/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:22:48 by msiitone          #+#    #+#             */
/*   Updated: 2023/11/17 01:20:13 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nsize(int size)
{
	size_t	i;

	i = 1;
	if (size <= 0)
		i++;
	while (size != 0)
	{
		i++;
		size = size / 10;
	}
	return (i - 1);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;
	long int	num;

	num = n;
	size = nsize(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[size - 1] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	return (str);
}
