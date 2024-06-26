/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:22:18 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/29 13:29:30 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct t_elem
{
	long int		value;
	int				place;
	int				*bin;
	struct t_elem	*next;
}	t_elem;

void	*ft_is_double(t_elem **list_a);
int		ft_len_list(t_elem **list_a);
void	ft_lil_sort(t_elem **list_a, t_elem **list_b, int len);
void	*ft_is_sorted(t_elem **list_a);
void	ft_free_list(t_elem **head);
void	ft_push(t_elem **list_a, t_elem **list_b, char c);
void	ft_insert(t_elem **head, long int value);
void	ft_simplify(t_elem **list_a);
void	ft_rotate(t_elem **head);
void	ft_free_tab(char **tab);
void	*ft_atoi_custom(char *str, t_elem **list);
void	ft_radix(t_elem **list_a, t_elem **list_b);
void	ft_reverse_rotate(t_elem **head);
void	ft_swap(t_elem **head, char c);

#endif