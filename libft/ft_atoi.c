/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:40:20 by antbonin          #+#    #+#             */
/*   Updated: 2024/11/22 15:28:42 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int		neg;
	long	number;

	number = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if ((*str) == 43 || *str == 45)
	{
		if (*(str++) == 45)
			neg = -1;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (number > (LONG_MAX - (*str - 48)) / 10)
		{
			if (neg == 1)
				return (-1);
			else
				return (0);
		}
		number = number * 10 + (*str - 48);
		str++;
	}
	return ((int)number * neg);
}
