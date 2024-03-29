# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:48:48 by eburnet           #+#    #+#              #
#    Updated: 2024/03/29 16:03:38 by eburnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = ft_push_rotate.c ft_lil_sort.c ft_utils.c ft_radix.c ft_atoi_custom.c main.c
OBJS = $(SRCS:.c=.o)
HEADERS = push_swap.h
LIBFT_PATH = ./libft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a
	cc $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME) -g3

%.o: %.c $(HEADERS)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
