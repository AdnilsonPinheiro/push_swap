/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:29:41 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/05 12:10:50 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_list	**stack_a;
//	t_list	**stack_b;

	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	// stack_b = malloc(sizeof(t_list));
	// if (!stack_b)
	// 	return (0);
	*stack_a = malloc(sizeof(t_list));
	if (!*stack_a)
		return (0);
	// *stack_b = malloc(sizeof(t_list));
	// if (!*stack_b)
	// 	return (0);
	(*stack_a)->next = NULL;
	(*stack_a)->prev = NULL;
//	*stack_b = NULL;
	int i = 3;
	while (i > 0)
	{
		t_list	*new;
		t_list	*current;

		current = *stack_a;
		new = malloc(sizeof(t_list));
		if (!new)
			return (0);
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->prev = current;
		new->next = NULL;
		new->rank = i;
		i--;
	}
	ft_sort(stack_a);
	/*t_list	**stack;
	int		i;

	if (argc > 1)
	{
		printf("pelo menos isso\n");
		stack = malloc(sizeof(t_list));
		if (!stack)
			return (0);
		*stack = NULL;
		ft_firstnode(stack, ft_atol(argv[1]));
		printf("created first node\n");
		i = 2;
		while (i < argc)
			ft_makelst(stack, ft_atol(argv[i++]));
		printf("made list\n");
		ft_repetition(stack);
		ft_rank(stack);
		ft_sort(stack);
	}*/
}
