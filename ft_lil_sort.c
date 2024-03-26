/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lil_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:32:13 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/26 17:15:17 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rasa_sara(t_elem **list_a, int version)
{
	if (version == 1)
	{
		ft_rotate(list_a);
		ft_swap(list_a, 'a');
	}
	else if (version == 2)
	{
		ft_swap(list_a, 'a');
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
			ft_swap(list_a, 'a');
	}
	else if (current->next->place > current->next->next->place)
	{
		if (current->next->next->place < current->place)
			ft_reverse_rotate(list_a);
		else
			ft_rasa_sara(list_a, 2);
	}
}

void	ft_search_move(t_elem **list_a, int searched, int len)
{
	t_elem	*current;
	int		i;
	int		j;

	i = 0;
	current = *list_a;
	if (current->place == searched)
		return ;
	while (current->place != searched)
	{
		current = current->next;
		i++;
	}
	current = *list_a;
	if (i <= len / 2)
	{
		while (i-- > 0)
			ft_rotate(list_a);
	}
	else
	{
		j = len - i;
		while (j-- > 0)
			ft_reverse_rotate(list_a);
	}
}

void	ft_lil_sort(t_elem **list_a, t_elem **list_b, int len)
{
	t_elem	*current;

	ft_simplify(list_a);
	current = *list_a;
	if (len == 2 && (current->place > current->next->place))
		ft_swap(list_a, 'a');
	else if (len == 3)
		ft_3_sort(list_a);
	else if (len == 4)
	{	
		ft_search_move(list_a, 1, len);
		ft_push(list_a, list_b, 'b');
		ft_3_sort(list_a);
		ft_push(list_b, list_a, 'a');
	}
	else if (len == 5)
	{
		ft_search_move(list_a, 1, len);
		ft_push(list_a, list_b, 'b');
		ft_search_move(list_a, 2, len - 1);
		ft_push(list_a, list_b, 'b');
		ft_3_sort(list_a);
		ft_push(list_b, list_a, 'a');
		ft_push(list_b, list_a, 'a');
	}	
}
