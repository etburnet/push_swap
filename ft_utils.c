/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:41:12 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/29 12:08:52 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_list(t_elem **list_a)
{
	t_elem	*current;
	int		i;

	i = 1;
	current = *list_a;
	while (current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	*ft_is_double(t_elem **list_a)
{
	t_elem	*temp;
	t_elem	*current;

	current = *list_a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->value == temp->value)
				return (&current->value);
			temp = temp->next;
		}
		current = current->next;
	}
	return (NULL);
}

void	*ft_is_sorted(t_elem **list_a)
{
	t_elem	*current;
	t_elem	*temp;

	current = *list_a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->value > temp->value)
				return (&current->value);
			temp = temp->next;
		}
		current = current->next;
	}
	return (NULL);
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

void	ft_simplify(t_elem **list_a)
{
	t_elem	*current;
	t_elem	*temp;
	int		place;

	current = *list_a;
	while (current != NULL)
	{
		temp = *list_a;
		place = 1;
		while (temp != NULL)
		{
			if (temp->value < current->value)
				place++;
			temp = temp->next;
		}
		current->place = place;
		current = current->next;
	}
}
