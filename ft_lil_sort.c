/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lil_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:32:13 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/22 15:25:03 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_elem **list)
{
	t_elem	*temp;
	t_elem	*last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	temp = *list;
	while (temp->next->next != NULL)
		temp = temp->next;
	last = temp->next;
	last->next = *list;
	*list = last;
	temp->next = NULL;
	ft_printf("rr\n");
}

void	ft_sa(t_elem **list)
{
	t_elem	*first;
	t_elem	*second;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second;
	ft_printf("sa\n");
}

void	ft_sort_3(t_elem **list)
{
	while (!ft_is_sorted(list))
	{
		if ((*list)->place > (*list)->next->place)
			ft_sa(list);
		if (!ft_is_sorted(list))
		{
			ft_rotate(list);
			ft_printf("ra\n");
		}
	}
}

int	ft_find_max(t_elem *list)
{
	int	max;

	max = list->place;
	while (list != NULL)
	{
		if (list->place > max)
			max = list->place;
		list = list->next;
	}
	return (max);
}

int	ft_find_min(t_elem *list)
{
	int	min;

	min = list->place;
	while (list != NULL)
	{
		if (list->place < min)
			min = list->place;
		list = list->next;
	}
	return (min);
}

void	ft_sort_5(t_elem **list_a, t_elem **list_b)
{
	int		max;
	t_elem	*current;

	current = *list_a;
	ft_printf("test");
	if (ft_len_list(list_a) <= 3)
	{
		ft_sort_3(list_a);
		return ;
	}
	max = ft_find_max(*list_a);
	if (ft_is_sorted(list_a))
		return ;
	if (current->place == max)
	{
		ft_rotate(list_a);
		ft_printf("ra\n");
	}
	else if (current->next->place == max)
		ft_rr(list_a);
	if ((*list_a)->next->place == ft_find_min(*list_a))
		ft_sa(list_a);
	ft_push(list_a, list_b);
	ft_printf("pb\n");
	ft_sort_3(list_a);
	ft_push(list_b, list_a);
	ft_printf("pa\n");
	if ((*list_a)->place == ft_find_max(*list_a))
	{
		ft_rotate(list_a);
		ft_printf("ra\n");
	}
	else if ((*list_a)->next->place == ft_find_max(*list_a))
		ft_rr(list_a);
}
