/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:34:22 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/22 13:58:05 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_create(long int value)
{
	t_elem	*new_elem;

	new_elem = malloc(sizeof(t_elem));
	if (new_elem != NULL)
	{
		new_elem->value = value;
		new_elem->place = 0;
		new_elem->bin = NULL;
		new_elem->next = NULL;
	}
	return (new_elem);
}

void	ft_insert(t_elem **head, long int value)
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

void	ft_push(t_elem **head_l1, t_elem **head_l2)
{
	t_elem	*first_l1;
	t_elem	*first_l2;

	if (*head_l1 == NULL)
        return; 
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

void	ft_free_list(t_elem **head)
{
	t_elem	*current;
	t_elem	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->bin);
		free(current);
		current = next;
	}
	*head = NULL;
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
}
