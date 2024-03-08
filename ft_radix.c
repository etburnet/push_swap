/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:22:12 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/08 15:11:18 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_d_to_b(t_elem **list_a)
{
	t_elem	*current;
	int		i;
	int		bits;
	int		temp;

	current = *list_a;
	while (current != NULL)
	{
		bits = 0;
		i = current->place;
		temp = current->place;
		while (i != 0)
		{
			bits++;
			i >>= 1;
		}
		current->bin = malloc(sizeof(int) * bits);
		if (current->bin == NULL)
			return ;
		i = bits - 1;
		while (i >= 0)
		{
			current->bin[i--] = current->place & 1;
			current->place >>= 1;
		}
		current->place = temp;
		current = current->next;
	}
}

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
		while (place != 0)
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

void	ft_radix(t_elem **list_a, t_elem **list_b)
{
	t_elem	*current;
	t_elem	*currentb;
	int		i;
	int		bin_max;
	
	i = 0;
	ft_simplify(list_a);
	ft_d_to_b(list_a);
	bin_max = ft_bin_max(list_a);
	while (i <= bin_max)
	{
		current = *list_a;
		currentb = *list_b;
		while (current != NULL)
		{
			if (current->bin[i] == 0)
			{
				ft_push(list_a, list_b);
				ft_printf("pb\n");
			}
			else
			{
				ft_rotate(list_a);
				ft_printf("ra\n");
			}
			current = current->next;
		}
		while (currentb != NULL)
		{
			ft_push(list_b, list_a);
			ft_printf("pa\n");
			currentb = currentb->next;
		}
		if (ft_is_sorted(list_a))
			return ;
		i++;
	}
}
