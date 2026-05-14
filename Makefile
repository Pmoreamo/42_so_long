# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 08:16:41 by pmorello          #+#    #+#              #
#    Updated: 2024/08/12 12:54:59 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/ft_check_errors.c \
	srcs/ft_valid_path.c \
	srcs/ft_movements.c \
	srcs/ft_graphics.c \
	srcs/ft_map.c \
	srcs/ft_utils.c \
	srcs/ft_keyboards.c \
	srcs/ft_clean_all.c \
	srcs/so_long.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_printf/ft_hexas.c \
	ft_printf/ft_numbers.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_text.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -Imlx -Iget_next_line -Ift_printf -Ilibrary

MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext -lm


all: make_mlx $(NAME)

make_mlx:
	@make -C mlx

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o:%.c Makefile so_long.h
	$(CC) $(CFLAGS) -c $< -o @$

clean: 
	@rm -rf $(OBJS)
	@make -C mlx clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all make_mlx clean fclean re
