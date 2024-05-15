/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:04:20 by msiitone          #+#    #+#             */
/*   Updated: 2024/02/07 18:23:25 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_num(int num, int *len)
{
	char	*str;

	str = ft_itoa(num);
	if (!str)
		*len = -1;
	ft_putstr_len(str, len);
	free(str);
}

void	ft_hexa(unsigned int i, int *len, char c)
{
	char	*hexa;
	char	str[20];
	int		j;

	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	j = 0;
	if (i == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (i != 0)
	{
		str[j] = hexa[i % 16];
		i = i / 16;
		j++;
	}
	while (j)
	{
		j--;
		ft_putchar_len(str[j], len);
	}
}

void	ft_ptr(size_t ptr, int *len)
{
	char	*hexa;
	char	str[20];
	int		i;

	hexa = "0123456789abcdef";
	if (write(1, "0x", 2) == -1)
	{
		*len = -1;
		return ;
	}
	(*len) += 2;
	if (ptr == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	i = 0;
	while (ptr != 0)
	{
		str[i] = hexa[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_unint(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unint(u / 10, len);
	ft_putchar_len(u % 10 + '0', len);
}
