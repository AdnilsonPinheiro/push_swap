/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:12:13 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 20:55:09 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rot(t_list **stack)
{
	t_list	*current;
	t_list	*node;
	t_list	*start;

	if (!stack || !*stack || ft_lstsize(stack) < 2)
		return ;
	current = *stack;
	node = *stack;
	start = (*stack)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	node->next = NULL;
	node->prev = current;
	start->prev = NULL;
	*stack = start;
}
