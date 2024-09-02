# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 09:53:34 by rbuitrag          #+#    #+#              #
#    Updated: 2024/08/27 10:07:52 by rbuitrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=leak

HEADER = inc/fractol.h
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
MLX_A = minilibx-linux/libmlx_Linux.a

CFILES =  main.c\
          string_utils.c\
          init.c\
          render.c\
          events.c\
          math_utils.c\
		  fractal_utils.c\
		  
OBJS = $(addprefix src/, $(CFILES:.c=.o))

all: library $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF)\
		$(MLX_A) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11\
		-lm -lz -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

library:
	@make -C libft
	@make -C printf
	@make -C minilibx-linux

clean:
	@make clean -C printf
	@make clean -C libft
	@make clean -C minilibx-linux
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C printf
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re library
