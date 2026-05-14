/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:15:22 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 11:32:57 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

void	ft_load_images(t_info *game)
{
	int	i;
	int	j;

	game->empty = mlx_xpm_file_to_image(game->mlx,
			"textures/empty.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &i, &j);
	game->object = mlx_xpm_file_to_image(game->mlx,
			"textures/coin.xpm", &i, &j);
}

int	main(int argc, char **argv)
{
	t_info	game;

	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(t_info));
		ft_read_map(&game, argv);
		if (ft_check_errors(&game, argv))
		{
			ft_map_destroyer(&game);
			return (1);
		}
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, (game.width * 90),
				(game.height * 90), "so_long");
		ft_load_images(&game);
		ft_adding_images(&game);
		mlx_key_hook(game.win, ft_movement, &game);
		mlx_hook(game.win, 17, 0, exit_win, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
