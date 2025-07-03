/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:12:13 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 18:44:09 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rot(t_list **stack)
{
	t_list	*last;
	t_list	*node;
	t_list	*start;

	if (!stack || !*stack || ft_lstsize(stack) < 2)
		return ;
	node = *stack;
	last = *stack;
	start = (*stack)->next;
	while (last->next != NULL)
		last = last->next;
	*stack = start;
	(*stack)->prev = NULL;
	last->next = node;
	node->prev = last;
	node->next = NULL;
}
