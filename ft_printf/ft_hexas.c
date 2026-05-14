/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:55:08 by pmorello          #+#    #+#             */
/*   Updated: 2024/03/16 13:29:55 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int numero, char type)
{
	int		result;
	char	*hu;
	char	*b;

	hu = "0123456789ABCDEF";
	b = "0123456789abcdef";
	result = 0;
	if (type == 'U')
		b = hu;
	if (numero < 16)
	{
		result += ft_putchar(*(b + numero));
		if (result == -1)
			return (-1);
	}
	if (numero >= 16)
	{
		result += ft_puthex(numero / 16, type);
		if (result == -1)
			return (-1);
		result += ft_puthex(numero % 16, type);
		if (result == -1)
			return (-1);
	}
	return (result);
}

int	ft_putpointer(unsigned long int numero, int times)
{
	int		result;
	char	*b;

	result = 0;
	b = "0123456789abcdef";
	if (times++ == 1)
	{
		result += ft_putstr("0x");
		if (result == -1)
			return (-1);
	}
	if (numero < 16)
	{
		result += ft_putchar(*(b + numero));
		if (result == -1)
			return (-1);
	}
	if (numero >= 16)
	{
		result += ft_putpointer(numero / 16, times);
		result += ft_putpointer(numero % 16, times);
	}
	if (result == -1)
		return (-1);
	return (result);
}
