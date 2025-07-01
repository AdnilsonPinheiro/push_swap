/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:29:41 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 18:42:31 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack;
	int		i;

	if (argc > 1)
	{
		stack = malloc(sizeof(t_list));
		if (!stack)
			return (0);
		*stack = NULL;
		ft_firstnode(stack, ft_atol(argv[1]));
		i = 2;
		while (i < argc)
			ft_makelst(stack, ft_atol(argv[i++]));
		ft_repetition(stack);
		ft_rank(stack);
		ft_sort(stack);
		ft_clearlst(stack);
	}
}
