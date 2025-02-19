/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:35:14 by akumari           #+#    #+#             */
/*   Updated: 2025/02/19 15:48:37 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h> //For debugging
#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <unistd.h>  //for write
#include <fcntl.h>

#define WIDTH 800
#define HEIGHT 800


int ft_strlen(char *str);
int	ft_strcmp(const char *s1, const char *s2);

#endif