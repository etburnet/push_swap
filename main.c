/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:34:44 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/06 16:59:36 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_str(int argc, char **argv, t_elem **list_a)
{
	int	i;

	i = 1;
	if (ft_strchr(argv[i], ' ') && argc > 2)
	{
		ft_printf("error\n");
		return 1;
	}
	while (i < argc)
	{
		ft_atoi_custom(argv[i], list_a);
		i++;
	}
	return 0;
}

int	ft_len_list(t_elem **list_a)
{
	t_elem	*last;
	int		i;

	i = 0;
	last = *list_a;
	while (last->next != NULL)
	{
		last = last->next;
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
				return &current->value;
			temp = temp->next;
		}
		current = current->next;
	}
}

void	*ft_is_sorted(t_elem **list_a)
{
	t_elem	*current;
	t_elem *temp;
	current = *list_a;

	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->value > temp->value)
				return &current->value;
			temp = temp->next;
		}
		current = current->next;
	}
}

void	ft_little_sort(t_elem **list_a)
{
	
}

int main(int argc, char *argv[])
{
	t_elem	*list_a;
	t_elem	*list_b;
	int		len;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
		return 1;
	if(ft_split_str(argc, argv, &list_a) == 0)
	{
		len = ft_len_list(&list_a);
		if (ft_is_double(&list_a) != NULL)
		{
			ft_printf("error\n");
			return 1;
		}
		if(ft_is_sorted(&list_a) != NULL)
		{
			ft_printf("pas Tier\n");
			if (len <= 3)
				ft_little_sort(&list_a);
			else
				ft_radix(&list_a, &list_b, len);
		}
		ft_printlist(list_a);
	}
	return 0;
}
