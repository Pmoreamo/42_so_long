/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:56:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/03 15:04:35 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

int	ft_check_format(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".ber", len) != 0)
	{
		ft_printf("Invalid format\n");
		return (1);
	}
	return (0);
}

int	ft_check_limits(t_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			ft_printf("Error\nMissing walls or invalid size!!\n");
			return (1);
		}
		i++;
	}
	j = 0;
	while (j < game->width)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
		{
			ft_printf("Error\nMissing walls or invalid size!!\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	ft_check_characters(t_info *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("Error\nInvalid characters, please check the map file\n");
		return (1);
	}
	if (game->map[height][width] == 'C')
		game->coincount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
	return (0);
}

int	ft_character_valid(t_info *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (width <= game->width)
		{
			if (ft_check_characters(game, height, width))
				return (1);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->coincount > 0
			&& game->exitcount == 1))
	{
		ft_printf("Error\nInvalid characters, please check the map file!!\n");
		return (1);
	}
	return (0);
}

int	ft_check_errors(t_info *game, char **argv)
{
	if (ft_check_format(argv))
		return (1);
	if (ft_check_limits(game))
		return (1);
	if (ft_character_valid(game))
		return (1);
	if (ft_check_path(game))
		return (1);
	return (0);
}
