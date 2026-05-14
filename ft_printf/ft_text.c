/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:33:11 by pmorello          #+#    #+#             */
/*   Updated: 2024/03/16 16:14:00 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	aux;

	aux = 0;
	i = 0;
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (s[i] != '\0' && aux >= 0)
	{
		aux = ft_putchar(s[i]);
		i++;
	}
	if (aux < 0)
		return (-1);
	return (i);
}
