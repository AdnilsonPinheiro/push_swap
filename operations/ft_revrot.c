/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:22:24 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/04 15:39:22 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_revrot(t_list **stack)
{
	t_list	*last;

	if (!stack || !*stack)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	last->prev->next = NULL;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
}
