/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:29:41 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/07 16:43:50 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_init(stack_a);
	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	(*stack_a)->num = ft_atol(argv[1]);
	i = 2;
	while (i < argc)
		ft_makelst(stack_a, ft_atol(argv[i++]));
	ft_repetition(stack_a);
	ft_rank(stack_a);
	ft_sort(stack_a, stack_b);
}
