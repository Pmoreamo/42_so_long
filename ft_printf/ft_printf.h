/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:43:41 by pmorello          #+#    #+#             */
/*   Updated: 2024/03/23 10:25:40 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Librerías
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

// Funciones
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnum(int n);
int		ft_putunum(unsigned int n);
int		ft_puthex(unsigned int numero, char str);
int		ft_putpointer(unsigned long int numero, int times);
int		ft_conversiones(va_list params, char const *str, int i);
int		ft_printf(char const *str, ...);

#endif
