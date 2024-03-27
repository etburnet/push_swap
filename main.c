/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:34:44 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/27 13:50:13 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_is_valid_argv(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j - 1] == '-' && argv[i][j] == '-')
				return (&argv[i][j]);
			if ((ft_isdigit(argv[i][j - 1]) && argv[i][j] == '-')
				|| (!ft_isdigit(argv[i][j + 1]) && argv[i][j] == '-'))
				return (&argv[i][j]);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (&argv[i][j]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	ft_is_int(t_elem **list_a)
{
	t_elem		*current;

	current = *list_a;
	while (current != NULL)
	{
		if (current->value > 2147483647 || current->value < -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

int	ft_split_str(int argc, char **argv, t_elem **list_a)
{
	int	i;

	i = 1;
	if (argc < 2 || ft_strlen(argv[i]) == 0)
		return (1);
	if ((ft_is_valid_argv(argv) != NULL)
		|| (ft_strchr(argv[i], ' ') && argc > 2))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (i < argc)
	{
		ft_atoi_custom(argv[i], list_a);
		i++;
	}
	if (ft_is_int(list_a) == 1)
		return (1);
	return (0);
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
			ft_putstr_fd("Error\n", 2);
			ft_free_list(&list_a);
			return (1);
		}
		if (ft_is_sorted(&list_a) != NULL)
		{
			if (len <= 5)
				ft_lil_sort(&list_a, &list_b, len);
			else
				ft_radix(&list_a, &list_b);
		}
	}
	ft_free_list(&list_a);
	return (0);
}
