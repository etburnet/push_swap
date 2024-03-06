/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:34:22 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/06 15:06:47 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_create(int value)
{
	t_elem	*new_elem;

	new_elem = malloc(sizeof(t_elem));
	if (new_elem != NULL)
	{
		new_elem->value = value;
		new_elem->bin = NULL;
		new_elem->next = NULL;
	}
	return (new_elem);
}

void	ft_insert(t_elem **head, int value)
{
	t_elem	*new_elem;
	t_elem	*current;

	new_elem = ft_create(value);
	if (new_elem != NULL)
	{
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
	else
		ft_printf("Erreur : création d'élément.\n");
}

void	move_botlist1_botlist2(t_elem **head_l1, t_elem **head_l2)
{
	t_elem	*last_l1;
	t_elem	*last_l2;
	t_elem	*previous;

	previous = NULL;
	last_l1 = *head_l1;
	while (last_l1->next != NULL)
	{
		previous = last_l1;
		last_l1 = last_l1->next;
	}
	if (previous != NULL)
		previous->next = NULL;
	else
		*head_l1 = NULL;
	if (*head_l2 == NULL)
		*head_l2 = last_l1;
	else
	{
		last_l2 = *head_l2;
		while (last_l2->next != NULL)
			last_l2 = last_l2->next;
		last_l2->next = last_l1;
	}
}

void	ft_printlist(t_elem *head)
{
	t_elem	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d -> ", current->value);
		current = current->next;
	}
	ft_printf("NULL\n");
}

void	ft_rotate(t_elem **head)
{
	t_elem	*last;
	t_elem	*previous;
	
	previous = NULL;
	last = *head;
	while (last->next != NULL)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *head;
	*head = last;
}
