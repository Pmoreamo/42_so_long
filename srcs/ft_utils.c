/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:14:31 by pmorello          #+#    #+#             */
/*   Updated: 2024/08/11 14:51:48 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = (char)c;
	return (s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && ((unsigned char)s1[i] != '\0'
			|| (unsigned char)s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			return (-1);
		}
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
