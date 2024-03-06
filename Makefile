# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:48:48 by eburnet           #+#    #+#              #
#    Updated: 2024/03/06 11:23:36 by eburnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_push_swap.c ft_radix.c ft_atoi_custom.c main.c
OBJS = $(SRCS:.c=.o)
HEADERS = push_swap.h

.c.o: 
	gcc $(CFLAGS) $(HEADERS) -c $<

$(NAME): $(OBJS)
	make -C ./libft
	ar rc $(NAME) $(OBJS) ./libft/libft.a
	
all : $(NAME)

clean :
	rm -f $(OBJS)
	make -C ./libft clean

fclean : clean
	rm -f $(NAME)
	make -C ./libft fclean

re : fclean all

.PHONY: all clean fclean re