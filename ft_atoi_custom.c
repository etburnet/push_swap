/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_custom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:23:33 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/22 11:07:10 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_custom(char *str, t_elem **list)
{
	int			i;
	int			isnegative;
	long int	result;

	i = 0;
	while (str[i])
	{
		isnegative = 1;
		result = 0;
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-' )
				isnegative *= -1;
			i++;
		}
		while (ft_isdigit(str[i]))
			result = result * 10 + (str[i++] - 48);
		ft_insert(list, result * isnegative);
	}
}
