/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:52:45 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/07 16:40:34 by adpinhei         ###   ########.fr       */
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
	i = 0;
	while (i < bits)
	{
		ft_printlst(stack_a, "A");
		ft_printlst(stack_b, "B");
		j = 0;
		while (j < (max_index + 1))
		{
			if((((*stack_a)->rank >> i) & 1) == 0)
				ft_push(stack_a, stack_b);
			else
				ft_rot(stack_a);
			j++;
		}
		while (*stack_b)
			ft_push(stack_b, stack_a);
		i++;
	}
	ft_printlst(stack_a, "A");
	ft_printlst(stack_b, "B");

	ft_isdone(stack_a, stack_b);
	
	/*bit = 1;
	ft_printlst(stack_a, "A");
	while (!ft_isdone(stack_a, stack_b))
	{
		ft_move_a(stack_a, stack_b, bit);

		// ft_printlst(stack_a, "A");
		// ft_printlst(stack_b, "B");

		ft_clean_b(stack_b, stack_a);

		// ft_printlst(stack_a, "A");
		// ft_printlst(stack_b, "B");

		printf("bit:%i\n", bit);
		bit = bit << 1;

	}
	ft_printlst(stack_a, "A");*/
}
