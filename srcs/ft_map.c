/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:34:52 by marvin            #+#    #+#             */
/*   Updated: 2024/09/03 13:01:14 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

static int	ft_width_map(char *str)
{
	int		width;

	width = 0;
	while (str[width] != '\0')
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

static int	ft_height_map(t_info *game, char *line)
{
	char	**map_h;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height++;
	map_h = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map_h)
		return (0);
	map_h[game->height] = NULL;
	while (i < game->height - 1)
	{
		map_h[i] = game->map[i];
		i++;
	}
	map_h[i] = line;
	if (game->map)
		free(game->map);
	game->map = map_h;
	return (1);
}

int	ft_read_map(t_info *game, char **argv)
{
	char	*height;

	game->fd = open(argv[1], O_RDONLY);
	if (!game->fd)
		return (0);
	while (game->fd)
	{
		height = get_next_line(game->fd);
		if (!ft_height_map(game, height))
			break ;
	}
	close (game->fd);
	if (!game->map || !game->map[0])
		return (0);
	game->width = ft_width_map(game->map[0]);
	return (1);
}
