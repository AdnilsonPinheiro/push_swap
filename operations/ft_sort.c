/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:52:45 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/07 20:30:25 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
//	ft_printlst(stack_a, "A");
//	ft_printlst(stack_b, "B");
	while (++i < bits)
	{
		j = 0;
		while (j < (max_index + 1))
		{
			if((((*stack_a)->rank >> i) & 1) == 0)
			{
				ft_push(stack_a, stack_b);
				ft_putstr(1, "pb\n");
			}
			else
			{
				ft_rot(stack_a);
				ft_putstr(1, "ra\n");
			}
			j++;
		}
		while (*stack_b)
		{
			ft_push(stack_b, stack_a);
			ft_putstr(1, "pa\n");
		}
	}
//	ft_printlst(stack_a, "A");
//	ft_printlst(stack_b, "B");
//	ft_isdone(stack_a, stack_b);
	ft_clearlst(stack_a);
	ft_clearlst(stack_b);
}
