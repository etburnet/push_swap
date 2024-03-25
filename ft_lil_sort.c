/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lil_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:32:13 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/25 17:20:10 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rasa_sara(t_elem **list_a, int version)
{
	if (version == 1)
	{
		ft_rotate(list_a);
		ft_swap(list_a);
	}
	else
	{
		ft_swap(list_a);
		ft_rotate(list_a);
	}
}

void	ft_3_sort(t_elem **list_a)
{
	t_elem	*current;

	current = *list_a;
	if (current->place > current->next->place)
	{
		if (current->place > current->next->next->place)
		{
			if (current->next->place > current->next->next->place)
				ft_rasa_sara(list_a, 1);
			else
				ft_rotate(list_a);
		}
		else
			ft_swap(list_a);
	}
	else if (current->next->place > current->next->next->place)
	{
		if (current->next->next->place < current->place)
			ft_reverse_rotate(list_a);
		else
			ft_rasa_sara(list_a, 2);
	}
}

void	ft_it(t_elem **list_a, t_elem **list_b, int *i, int *j, int	*iter)
{
	if (*i < *iter)
	{
		*j = *i;
		while (*i > 0)
		{
			ft_rotate(list_a);
			(*i)--;
		}
		ft_push(list_b, list_a);
		ft_printf("pa\n");
		while (*j > 0)
		{
			ft_reverse_rotate(list_a);
			(*j)--;
		}
	}
	else
	{
		ft_push(list_b, list_a);
		ft_printf("pa\n");
		ft_rotate(list_a);
	}
}

void	ft_4_5_sort(t_elem **list_a, t_elem **list_b, int i)
{
	int		j;
	int		iter;
	t_elem	*current_a;
	t_elem	*current_b;
	
	current_b = *list_b;
	iter = 3;
	while (current_b != NULL)
	{
		i = 0;
		current_a = *list_a;
		j = 3;
		while (current_b->place > current_a->place && i < j)
		{
			if (current_a->next != NULL)
				current_a = current_a->next;
			i++;
		}
		ft_it(list_a, list_b, &i, &j, &iter);
		current_b = *list_b;
		iter = 4;
	}
}

void	ft_lil_sort(t_elem **list_a, t_elem **list_b, int len)
{
	t_elem	*current;
	int		i;
	
	ft_simplify(list_a);
	current = *list_a;
	i = len - 3;
	while (i > 0)
	{
		ft_push(list_a, list_b);
		ft_printf("pb\n");
		i--;
	}
	if (len == 2 && (current->place > current->next->place))
		ft_printf("sa\n");
	else
	{	
		ft_3_sort(list_a);
		if (len == 4 || len == 5)
			ft_4_5_sort(list_a, list_b, i);
	}
}
