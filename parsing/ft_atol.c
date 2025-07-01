/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:39:40 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 17:10:08 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int long	ft_atol(char *str)
{
	int long	res;
	int			i;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res * sign < INT_MIN || res * sign > INT_MAX)
		exit (0);
	return (res * sign);
}
