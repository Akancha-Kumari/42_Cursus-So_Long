/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:55:49 by akumari           #+#    #+#             */
/*   Updated: 2025/03/10 15:59:48 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if ((unsigned const char)s1[i] != (unsigned const char)s2[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		*(str + i) = c;
		i++;
	}
	return (str);
}

char	*ft_strdup(char *src)
{
	char	*cpy_str;
	size_t	i;

	cpy_str = (char *)malloc(ft_strlen(src) + 1);
	if (cpy_str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		cpy_str[i] = src[i];
		i++;
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}
