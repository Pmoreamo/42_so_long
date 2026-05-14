/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:19:28 by pmorello          #+#    #+#             */
/*   Updated: 2024/08/11 14:44:03 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

int	ft_w(t_info *game, int movement)
{
	int	i;
	int	j;
	int	rm;

	i = game->x;
	j = game->y;
	if (movement == XK_w)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		rm = ft_right_move(game, i, j);
		if (!rm)
			return (0);
		game->map[j + 1][i] = '0';
	}
	ft_printf("Steps: %i\n", game->counter);
	ft_printf("Coins Left: %i\n", game->objects_picked);
	return (1);
}

int	ft_s(t_info *game, int movement)
{
	int	i;
	int	j;
	int	rm;

	i = game->x;
	j = game->y;
	if (movement == XK_s)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		rm = ft_right_move(game, i, j);
		if (!rm)
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Step: %i\n", game->counter);
	ft_printf("Coins Left: %i\n", game->objects_picked);
	return (1);
}

int	ft_a(t_info *game, int movement)
{
	int	i;
	int	j;
	int	rm;

	i = game->x;
	j = game->y;
	if (movement == XK_a)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		rm = ft_right_move(game, i, j);
		if (!rm)
			return (0);
		game->map[j][i + 1] = '0';
	}
	ft_printf("Step: %i\n", game->counter);
	ft_printf("Coins Left: %i\n", game->objects_picked);
	return (1);
}

int	ft_d(t_info *game, int movement)
{
	int	i;
	int	j;
	int	rm;

	i = game->x;
	j = game->y;
	if (movement == XK_d)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		rm = ft_right_move(game, i, j);
		if (!rm)
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Step: %i\n", game->counter);
	ft_printf("Coins Left: %i\n", game->objects_picked);
	return (1);
}
