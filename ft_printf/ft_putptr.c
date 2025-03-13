/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:30:58 by akumari           #+#    #+#             */
/*   Updated: 2024/11/22 11:19:30 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long val, int *count)
{
	if (!val)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_puthex(val, 'x', count);
	}
}
