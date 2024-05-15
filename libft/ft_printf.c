/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:29:37 by msiitone          #+#    #+#             */
/*   Updated: 2024/02/07 18:14:42 by msiitone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_len(char c, int *len)
{
	int	err;

	if (*len == -1)
		return ;
	err = write(1, &c, 1);
	(*len)++;
	if (err == -1)
		(*len) = -1;
}

void	ft_putstr_len(char *args, int *len)
{
	size_t	i;

	if (*len == -1)
		return ;
	i = 0;
	if (!args)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*len = -1;
			return ;
		}
		(*len) += 6;
		return ;
	}
	while (args[i])
	{
		ft_putchar_len(args[i], len);
		i++;
		if (*len == -1)
			return ;
	}
}

int	ft_check(const char c, va_list *args, int *len, int *i)
{
	if (*len == -1)
		return (-1);
	else if (c == 's')
		ft_putstr_len(va_arg(*args, char *), len);
	else if (c == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (c == 'p')
		ft_ptr(va_arg(*args, size_t), len);
	else if (c == 'd' || c == 'i')
		ft_num(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unint(va_arg(*args, unsigned int), len);
	else if (c == 'x')
		ft_hexa(va_arg(*args, unsigned int), len, 'x');
	else if (c == 'X')
		ft_hexa(va_arg(*args, unsigned int), len, 'X');
	else if (c == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (len == -1)
			return (-1);
		else if (str[i] == '%')
		{
			i++;
			ft_check(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
