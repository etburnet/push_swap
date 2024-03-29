/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_custom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:23:33 by eburnet           #+#    #+#             */
/*   Updated: 2024/03/29 14:38:56 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	*ft_atoi_custom(char *str, t_elem **list)
{
	int			isnegative;
	long int	result;
	long int	temp;

	while (*str)
	{
		temp = 0;
		isnegative = 1;
		result = 0;
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-' && str++)
			isnegative *= -1;
		while (ft_isdigit(*str))
		{
			result = result * 10 + (*str++ - 48);
			if (temp > result)
				return (str);
			temp = result;
		}
		ft_insert(list, result * isnegative);
	}
	return (NULL);
}
