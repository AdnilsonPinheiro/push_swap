/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:52:45 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 21:24:39 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_pass(t_list **lst);

void	ft_sort(t_list **stack_a)
{
	t_list	**stack_b;
	int		pass;
	int		bit;

	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return ;
	*stack_b = NULL;
	pass = ft_pass(stack_a);
	bit = 0;
	while (pass > 0)
	{
		ft_isdone(stack_a, stack_b);

		// ft_printlst(stack_a, "stack_a");
		// ft_printlst(stack_b, "stack_b");
		// ft_putstr(1, "**********\n");

		ft_move_a(stack_a, stack_b, bit);

		// ft_printlst(stack_a, "stack_a");
		// ft_printlst(stack_b, "stack_b");
		// ft_putstr(1, "***********\n");

		ft_move_b(stack_b, stack_a, bit);
		bit++;
		pass--;
	}
}

static int	ft_pass(t_list **lst)
{
	t_list			*current;
	unsigned int	max;
	int				bit;

	current = *lst;
	max = current->rank;
	while (current->next != NULL)
	{
		if (current->rank > max)
			max = current->rank;
		current = current->next;
	}
	bit = 31;
	while ((max >> bit & 1) == 0)
		bit--;
	return (++bit);
}
