/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:53:59 by pmorello          #+#    #+#             */
/*   Updated: 2024/09/03 13:31:22 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

static void	ft_free_way(t_path *p, int map_height)
{
	int	k;

	k = -1;
	if (p->map)
	{
		while (++k < map_height)
			free(p->map[k]);
		free(p->map);
	}
	p->map = NULL;
}

static void	ft_map_to_check(t_path *p, t_info *game)
{
	int	height;
	int	width;

	p->map = malloc(sizeof(int *) * game->height);
	if (!p->map)
		return ;
	height = 0;
	while (height < game->height)
	{
		p->map[height] = malloc(sizeof(int) * game->width);
		if (!p->map[height])
			return ;
		height++;
	}
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			p->map[height][width] = 0;
			width++;
		}
		height++;
	}
}

static void	ft_check_cells(t_path *p, t_info *game, int row, int col)
{
	if (p->objects_left == 0)
		return ;
	if (p->map[row][col] == 0 && game->map[row][col] != '1')
	{
		p->map[row][col] = 1;
		if (game->map[row][col] == 'E' || game->map[row][col] == 'C')
			p->objects_left--;
		if (game->map[row][col] == 'E')
			return ;
		ft_check_cells(p, game, row + 1, col);
		ft_check_cells(p, game, row - 1, col);
		ft_check_cells(p, game, row, col + 1);
		ft_check_cells(p, game, row, col - 1);
	}
}

static	int	ft_is_posible(t_info *game, int p_i, int p_j, int left)
{
	t_path	p;

	p.objects_left = left;
	ft_map_to_check(&p, game);
	ft_check_cells(&p, game, p_i, p_j);
	if (p.objects_left != 0)
	{
		ft_printf("Error\nNo valid path found!!\n");
		ft_free_way(&p, game->height);
		return (1);
	}
	ft_free_way(&p, game->height);
	return (0);
}

int	ft_check_path(t_info *game)
{
	int	i[2];
	int	j[2];
	int	left;

	left = 0;
	i[0] = -1;
	while (game->map[++i[0]])
	{
		j[0] = -1;
		while (game->map[i[0]][++j[0]])
		{
			if (game->map[i[0]][j[0]] == 'P')
			{
				i[1] = i[0];
				j[1] = j[0];
			}
			if (game->map[i[0]][j[0]] == 'E' || game->map[i[0]][j[0]] == 'C')
				left++;
		}
	}
	if (ft_is_posible(game, i[1], j[1], left) == 1)
		return (1);
	return (0);
}
