/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:46:46 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 11:29:02 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

static void	img_destroyer(t_info *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->object)
		mlx_destroy_image(game->mlx, game->object);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->empty)
		mlx_destroy_image(game->mlx, game->empty);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
}

void	ft_map_destroyer(t_info *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
		}
		i++;
	}
	free(game->map);
}

int	mlx_map_destroyer(t_info *game)
{
	img_destroyer(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_map_destroyer(game);
	exit(0);
}

int	exit_win(t_info *game)
{
	mlx_map_destroyer(game);
	return (0);
}
