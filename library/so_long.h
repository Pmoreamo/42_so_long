/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:17:46 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 11:29:37 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <X11/keysym.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_info
{
	int		fd;
	int		height;
	int		width;
	int		playercount;
	int		coincount;
	int		exitcount;
	int		x;
	int		y;
	int		counter;
	int		objects_picked;

	char	**map;

	void	*empty;
	void	*wall;
	void	*player;
	void	*exit;
	void	*object;
	void	*mlx;
	void	*win;
}	t_info;

typedef struct s_path
{
	int		**map;
	int		objects_left;
}	t_path;

//utils
void		*ft_memset(void *s, int c, size_t n);
int			ft_strlen(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

//map
int			ft_read_map(t_info *game, char **argv);
void		ft_load_images(t_info *game);
void		ft_adding_images(t_info *game);
int			mlx_map_destroyer(t_info *game);
void		ft_map_destroyer(t_info *game);
int			exit_win(t_info *game);

//check
int			ft_check_errors(t_info *game, char **argv);
int			ft_check_path(t_info *game);

//controls
int			ft_movement(int command, t_info *game);
int			ft_right_move(t_info *game, int i, int j);
int			ft_w(t_info *game, int movement);
int			ft_s(t_info *game, int movement);
int			ft_a(t_info *game, int movement);
int			ft_d(t_info *game, int movement);
#endif
