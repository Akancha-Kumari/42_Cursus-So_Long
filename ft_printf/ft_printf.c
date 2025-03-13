/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:41:13 by akumari           #+#    #+#             */
/*   Updated: 2024/12/09 14:39:01 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_type(const char *format, int *i, va_list arg, int *count)
{
	if (format[*i] == '%')
		ft_putchar('%', count);
	else if (format[*i] == 'c')
		ft_putchar(va_arg(arg, int), count);
	else if (format[*i] == 's')
		ft_putstr(va_arg(arg, char *), count);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr(va_arg(arg, int), count);
	else if (format[*i] == 'p')
		ft_putptr(va_arg(arg, unsigned long long), count);
	else if (format[*i] == 'u')
		ft_putunbr(va_arg(arg, unsigned int), count);
	else if (format[*i] == 'x' || format[*i] == 'X')
		ft_puthex(va_arg(arg, unsigned int), format[*i], count);
	else
	{
		ft_putstr("Invalid Specifier: %", count);
		ft_putchar(format[*i], count);
		*count = -1;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i] != '\0' && count != -1)
	{
		if (format[i] == '%')
		{
			i++;
			ft_type(format, &i, arg, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(arg);
	return (count);
}
