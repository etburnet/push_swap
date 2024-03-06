/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:22:18 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/06 16:35:21 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct	t_elem
{
	int				value;
	int				*bin;
	struct t_elem	*next;
} t_elem;

void	move_botlist1_botlist2(t_elem **head_l1, t_elem **head_l2);
void	ft_printlist(t_elem *head);
void	ft_insert(t_elem **head, int value);
t_elem	*ft_create(int value);
void	ft_rotate(t_elem **head);
void	ft_atoi_custom(char *str, t_elem **list);
void    ft_radix(t_elem **list_a, t_elem **list_b, int len);

#endif