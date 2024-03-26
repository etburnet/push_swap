/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:22:12 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/26 14:15:20 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bin_max(t_elem **list_a)
{
	t_elem	*current;
	int		place;
	int		max_len;
	int		bits;

	max_len = 0;
	current = *list_a;
	while (current != NULL)
	{
		bits = 0;
		place = current->place;
		while (place > 0)
		{
			bits++;
			place >>= 1;
		}
		if (bits > max_len)
			max_len = bits;
		current = current->next;
	}
	return (max_len);
}

void	ft_d_to_b(t_elem **list_a)
{
	t_elem	*current;
	int		i;
	int		max_bits;
	int		temp;

	max_bits = ft_bin_max(list_a);
	current = *list_a;
	while (current != NULL)
	{
		temp = current->place;
		current->bin = malloc(sizeof(int) * max_bits);
		if (current->bin == NULL)
			return ;
		i = max_bits - 1;
		while (i >= 0)
		{
			current->bin[i] = current->place & 1;
			current->place >>= 1;
			i--;
		}
		current->place = temp;
		current = current->next;
	}
}

void	ft_bin_sort(t_elem **list_a, t_elem **list_b, int *bin_max)
{
	t_elem	*current;
	int		len_list;
	int		j;

	current = *list_a;
	j = 0;
	(*bin_max)--;
	len_list = ft_len_list(list_a);
	while (j < len_list && current != NULL)
	{
		if (current->bin[*bin_max] == 0)
			ft_push(list_a, list_b, 'b');
		else if (current->bin[*bin_max] == 1)
			ft_rotate(list_a);
		j++;
		current = *list_a;
	}
}

void	ft_radix(t_elem **list_a, t_elem **list_b)
{
	int		bin_max;

	ft_simplify(list_a);
	ft_d_to_b(list_a);
	bin_max = ft_bin_max(list_a);
	while (bin_max >= 0)
	{
		ft_bin_sort(list_a, list_b, &bin_max);
		while (*list_b != NULL)
			ft_push(list_b, list_a, 'a');
		if (ft_is_sorted(list_a) == NULL)
			return ;
	}
}
