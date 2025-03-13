/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:21:10 by akumari           #+#    #+#             */
/*   Updated: 2024/12/05 11:15:39 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", count);
	}
	else
	{
		while (str[i] != '\0')
		{
			if (write(1, &str[i], 1) == -1)
				*count = -1;
			else
				(*count)++;
			i++;
		}
	}
}
