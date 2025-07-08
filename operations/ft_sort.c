/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:52:45 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/08 17:53:43 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_fix_b(t_list **stack_b, t_list **stack_a);
static void	ft_change(t_list **stack_a, t_list **stack_b, int i);

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int		bits;
	int		i;
	int		j;
	int		max_index;

	bits = 0;
	max_index = ft_lstsize(stack_a) - 1;
	while (max_index >> bits)
		bits++;
	i = -1;
	while (++i < bits)
	{
		j = -1;
		while (++j < (max_index + 1))
			ft_change(stack_a, stack_b, i);
		while (*stack_b)
			ft_fix_b(stack_b, stack_a);
	}
	ft_cleanlst(stack_a);
	ft_cleanlst(stack_b);
}

static void	ft_fix_b(t_list **stack_b, t_list **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_putstr(1, "pa");
}

static void	ft_change(t_list **stack_a, t_list **stack_b, int i)
{
	if (!*stack_a)
		return ;
	if ((((*stack_a)->rank >> i) & 1) == 0)
	{
		ft_push(stack_a, stack_b);
		ft_putstr(1, "pb");
	}
	else
	{
		ft_rot(stack_a);
		ft_putstr(1, "ra");
	}
}
