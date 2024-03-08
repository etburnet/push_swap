/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:34:44 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/08 15:12:16 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_str(int argc, char **argv, t_elem **list_a)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (1);
	if ((ft_strchr(argv[i], ' ') && argc > 2) || ft_strlen(argv[i]) == 0)
	{
		ft_printf("error\n");
		return (1);
	}
	while (i < argc)
	{
		if (ft_atoi_custom(argv[i], list_a))
		{
			ft_printf("error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_little_sort(t_elem **list_a, int len)
{
	t_elem	*current;

	current = *list_a;
	if (len == 2 && (current->value > current->next->value))
		ft_printf("sa\n");
	else if (len == 3 && (current->value > current->next->value))
	{
		if (current->value > current->next->next->value)
		{
			if (current->next->value > current->next->next->value)
				ft_printf("ra\nsa\n");
			else
				ft_printf("ra\n");
		}
		else
			ft_printf("sa\n");
	}
	else if (len == 3 && (current->next->value > current->next->next->value))
	{
		if (current->next->next->value < current->value)
			ft_printf("rra\n");
		else
			ft_printf("sa\nra\n");
	}
}

int	main(int argc, char *argv[])
{
	t_elem	*list_a;
	t_elem	*list_b;
	int		len;

	list_a = NULL;
	list_b = NULL;
	if (ft_split_str(argc, argv, &list_a) == 0)
	{
		len = ft_len_list(&list_a);
		if (ft_is_double(&list_a) != NULL)
		{
			ft_printf("error\n");
			return (1);
		}
		if (ft_is_sorted(&list_a) != NULL)
		{
			if (len <= 3)
				ft_little_sort(&list_a, len);
			else
				ft_radix(&list_a, &list_b);
		}
	}
	ft_free_list(&list_a);
	return (0);
}
