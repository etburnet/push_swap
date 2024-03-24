/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lil_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:32:13 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/24 16:41:57 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_elem **head)
{
	t_elem	*av_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	av_last = *head;
	while (av_last->next->next != NULL)
		av_last = av_last->next;
	av_last->next = *head;
	av_last = NULL;
	ft_printf("rra\n");
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
				ft_printf("ra\nsa\n");
			else
				ft_printf("ra\n");
		}
		else
			ft_printf("sa\n");
	}
	else if (current->next->place > current->next->next->place)
	{
		if (current->next->next->place < current->place)
			ft_printf("rra\n");
		else
			ft_printf("sa\nra\n");
	}
}

void	ft_4_5_sort(t_elem **list_a, t_elem **list_b, int len)
{
	int		i;
	int		j;
	t_elem	*current_a;
	t_elem	*current_b;
	
	current_a = *list_a;
	current_b = *list_b;
	i = len - 3;
	while (i > 0)
	{
		ft_push(list_a, list_b);
		ft_printf("pb\n");
		i--;
	}
	ft_3_sort(list_a);
	while (current_b != NULL) //
	{
		while (current_a->place > current_b->place)
			i++;
		if (i < 3)
		{
			j = i;
			while (i > 0)
			{
				ft_rotate(list_a);
				ft_printf("ra\n");
				i--;
			}
			ft_push(list_b, list_a);
			while (j > 0)
			{
				ft_reverse_rotate(list_a);
				j--;
			}
		}
		else
		{
			ft_push(list_b, list_a);
			ft_printf("pa\n");
			ft_rotate(list_a);
			ft_printf("ra\n");
		}
		current_b = current_b->next;
	}
	
}

void	ft_lil_sort(t_elem **list_a, t_elem **list_b, int len)
{
	t_elem	*current;

	current = *list_a;
	if (len == 2 && (current->place > current->next->place))
		ft_printf("sa\n");
	else if (len == 3)
		ft_3_sort(list_a);
	else if (len == 4 || len == 5)
		ft_4_5_sort(list_a, list_b, len);
	else
		return ;
}
