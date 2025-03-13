/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:17:24 by akumari           #+#    #+#             */
/*   Updated: 2024/12/05 11:21:06 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long num, int format, int *count)
{
	char	*hex;

	if (num > 15)
		ft_puthex(num / 16, format, count);
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (write(1, &hex[num % 16], 1) == -1)
		*count = -1;
	else
		(*count)++;
}
