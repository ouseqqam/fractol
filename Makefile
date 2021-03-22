# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 14:13:24 by ouseqqam          #+#    #+#              #
#    Updated: 2020/01/01 17:01:41 by ouseqqam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

CFLAGS = -Wall -Werror -Wextra

mlx = -lmlx -framework OpenGL -framework AppKit

FILE = main.c event.c fractol.c exec_fract.c zoom.c ft_strcmp.c ft_putendl.c menu.c

INC = fractol.h

SRC = $(FILE:.c=.o)

all:$(NAME)

$(NAME): $(SRC) $(INC)
	          @cc $(mlx) -o  $(NAME)  $(FILE)
clean:
	          @rm -f $(SRC)

fclean: clean
	          @rm -f $(NAME)

re: fclean all
