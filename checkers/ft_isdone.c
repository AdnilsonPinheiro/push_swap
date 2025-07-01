/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:32:24 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 19:39:20 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_isdone(t_list **master, t_list **serv)
{
	t_list	*current;

	if (ft_lstsize(serv) > 0)
		return ;
	current = *master;
	while (current->next != NULL)
	{
		if (current->num < current->next->num)
			current = current->next;
		else
			return ;
	}
	ft_putstr(1, "stack_a is ordered!");
	ft_printlst(master, "stack_a");
	exit (0);
}
