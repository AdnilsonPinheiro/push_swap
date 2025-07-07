/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:32:24 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/05 11:47:30 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdone(t_list **master, t_list **serv)
{
	t_list	*current;
	int		size;

	if (ft_lstsize(serv) > 0)
		return (0);
	size = ft_lstsize(master);
	current = *master;
	while (size > 0 && current->next)
	{
		if (current->rank > current->next->rank)
			return (0);
		current = current->next;
		size--;
	}
	ft_putstr(1, "stack_a is sorted\n");
	return (1);
}
