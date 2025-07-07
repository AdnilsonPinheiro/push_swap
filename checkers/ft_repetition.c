/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repetition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:18:31 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 20:19:22 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_repetition(t_list **lst)
{
	t_list		*first;
	t_list		*second;
	int long	i;
	int			counter;

	first = *lst;
	counter = 0;
	while (counter < ft_lstsize(lst))
	{
		i = first->num;
		second = first->next;
		while (second)
		{
			if (second->num == i)
				ft_error();
			second = second->next;
		}
		first = first->next;
		counter++;
	}
}
