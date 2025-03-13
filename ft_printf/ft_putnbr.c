/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:33:21 by akumari           #+#    #+#             */
/*   Updated: 2024/12/05 09:48:39 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *count)
{
	long	nbr;

	nbr = num;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, count);
	ft_putchar(nbr % 10 + '0', count);
}
