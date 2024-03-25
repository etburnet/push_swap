/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:34:22 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/25 16:27:25 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert(t_elem **head, long int value)
{
	t_elem	*new_elem;
	t_elem	*current;

	new_elem = malloc(sizeof(t_elem));
	if (new_elem != NULL)
	{
		new_elem->value = value;
		new_elem->place = 0;
		new_elem->bin = NULL;
		new_elem->next = NULL;
		if (*head == NULL)
			*head = new_elem;
		else
		{
			current = *head;
			while (current->next != NULL)
				current = current->next;
			current->next = new_elem;
		}
	}
}

void	ft_push(t_elem **head_l1, t_elem **head_l2)
{
	t_elem	*first_l1;
	t_elem	*first_l2;

	if (*head_l1 == NULL)
		return ;
	first_l1 = *head_l1;
	*head_l1 = first_l1->next;
	first_l2 = *head_l2;
	if (first_l2 == NULL)
	{
		*head_l2 = first_l1;
		first_l1->next = NULL;
	}
	else
	{
		first_l1->next = first_l2;
		*head_l2 = first_l1;
	}
}

void	ft_rotate(t_elem **head)
{
	t_elem	*last;
	t_elem	*first;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	first = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	*head = first->next;
	first->next = NULL;
	ft_printf("ra\n");
}

void	ft_reverse_rotate(t_elem **head)
{
	t_elem	*first;
	t_elem	*av_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	av_last = *head;
	first = *head;
	while (av_last->next->next != NULL)
		av_last = av_last->next;
	av_last->next->next = first;
	*head = av_last->next;
	av_last->next = NULL;
	ft_printf("rra\n");
}

void	ft_swap(t_elem **head)
{
	t_elem	*first;	
	t_elem	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	*head = second;
	second->next = first;
	ft_printf("sa\n");
}
