# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:48:48 by eburnet           #+#    #+#              #
#    Updated: 2024/03/08 15:20:20 by eburnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_push_rotate.c ft_utils.c ft_radix.c ft_atoi_custom.c main.c
OBJS = $(SRCS:.c=.o)
HEADERS = push_swap.h
LIBFT_PATH = ./libft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a
	ar rc $(NAME) $(OBJS) $(LIBFT_PATH)/libft.a

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
