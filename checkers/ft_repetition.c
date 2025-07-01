/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repetition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:18:31 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 16:37:21 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_repetition(t_list **lst)
{
	t_list		*first;
	t_list		*second;
	int long	i;

	first = *lst;
	while (first->next != NULL)
	{
		i = first->num;
		second = first->next;
		while (second->next != NULL)
		{
			if (second->num == i)
			{
				ft_putstr(2, "repetition");
				exit (0);
			}
			second = second->next;
		}
		first = first->next;
	}
}
