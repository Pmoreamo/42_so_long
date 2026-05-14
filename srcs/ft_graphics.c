/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:04:25 by marvin            #+#    #+#             */
/*   Updated: 2024/08/11 14:39:40 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

void	ft_load_player(t_info *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player, width * 90, height * 90);
	game->y = height;
	game->x = width;
}

void	ft_load_object(t_info *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->object, width * 90, height * 90);
	game->objects_picked++;
}

void	ft_load_wall(t_info *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall, width * 90, height * 90);
}

void	ft_load_empty(t_info *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->empty, width * 90, height * 90);
}

void	ft_adding_images(t_info *game)
{
	int	height;
	int	width;

	game->objects_picked = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				ft_load_wall(game, height, width);
			else if (game->map[height][width] == '0')
				ft_load_empty(game, height, width);
			else if (game->map[height][width] == 'C')
				ft_load_object(game, height, width);
			else if (game->map[height][width] == 'P')
				ft_load_player(game, height, width);
			else if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit, width * 90, height * 90);
			width++;
		}
		height++;
	}
}
