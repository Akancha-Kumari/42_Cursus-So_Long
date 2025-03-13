/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:39:38 by akumari           #+#    #+#             */
/*   Updated: 2024/11/22 09:23:54 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int nbr, int *count)
{
	if (nbr == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (nbr > 9)
		ft_putunbr(nbr / 10, count);
	ft_putchar(nbr % 10 + 48, count);
}
