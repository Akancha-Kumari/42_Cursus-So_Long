/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:55:49 by akumari           #+#    #+#             */
/*   Updated: 2025/02/19 14:56:00 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i = 0;
	while ((s1[i] || s2[i]))
	{
		if ((unsigned const char)s1[i] != (unsigned const char)s2[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		i++;
	}
	return (0);
}
