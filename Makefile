# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 10:48:43 by moel-asr          #+#    #+#              #
#    Updated: 2022/11/24 13:43:49 by moel-asr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror 

SRCS = get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c \
	so_long_utils/ft_putchar.c \
	so_long_utils/ft_putnbr.c \
	so_long_utils/ft_putstr.c \
	so_long_utils/ft_strcmp.c \
	so_long_utils/ft_strstr.c \
	so_long_srcs/check_errors.c \
	so_long_srcs/check_path_and_map.c \
	so_long_srcs/print_errors.c \
	so_long_srcs/clear_window.c \
	so_long_srcs/draw_image.c \
	so_long_srcs/mlx_keys.c \
	so_long_srcs/mlx.c \
	main.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean bonus
