/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:50:41 by akumari           #+#    #+#             */
/*   Updated: 2024/11/22 10:32:31 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
void	ft_putunbr(unsigned int nbr, int *count);
void	ft_putptr(unsigned long val, int *count);
void	ft_putnbr(int num, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putchar(int c, int *count);
void	ft_puthex(unsigned long num, int format, int *count);

#endif