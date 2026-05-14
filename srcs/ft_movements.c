/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:15:37 by pmorello          #+#    #+#             */
/*   Updated: 2024/08/12 12:55:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

int	ft_right_move(t_info *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->objects_picked != 0)
			return (0);
		ft_printf("Congratulations!!\n");
		mlx_map_destroyer(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->objects_picked--;
		game->counter++;
	}
	return (1);
}

int	ft_movement(int command, t_info *game)
{
	int	works;

	if (command == XK_Escape)
		mlx_map_destroyer(game);
	if (command == XK_w)
		works = ft_w(game, command);
	if (command == XK_s)
		works = ft_s(game, command);
	if (command == XK_a)
		works = ft_a(game, command);
	if (command == XK_d)
		works = ft_d(game, command);
	if (works)
		ft_adding_images(game);
	return (0);
}
