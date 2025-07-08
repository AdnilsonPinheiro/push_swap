/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:29:41 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/08 17:33:16 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_two(char *str1, char *str2);
static void	ft_sort_three(char *str1, char *str2, char *str3);
static void	ft_swipe(t_list **stack_a, t_list **stack_b);

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		i;

	if (argc == 3)
		ft_sort_two(argv[1], argv[2]);
	else if (argc == 4)
		ft_sort_three(argv[1], argv[2], argv[3]);
	else if (argc > 4)
	{
		stack_a = NULL;
		stack_b = NULL;
		stack_a = ft_init(stack_a);
		stack_b = malloc(sizeof(t_list *));
		*stack_b = NULL;
		(*stack_a)->num = ft_atol(argv[1]);
		i = 2;
		while (i < argc)
			ft_makelst(stack_a, ft_atol(argv[i++]));
		if (ft_repetition(stack_a))
			ft_swipe(stack_a, stack_b);
		ft_isdone(stack_a, stack_b);
		ft_rank(stack_a);
		ft_sort(stack_a, stack_b);
	}
}

static void	ft_sort_two(char *str1, char *str2)
{
	long int	a;
	long int	b;

	a = ft_atol(str1);
	b = ft_atol(str2);
	if (a == b)
		ft_error();
	else if (a > b)
		ft_putstr(1, "sa");
	else
		return ;
}

static void	ft_sort_three(char *str1, char *str2, char *str3)
{
	long int	a;
	long int	b;
	long int	c;

	a = ft_atol(str1);
	b = ft_atol(str2);
	c = ft_atol(str3);
	if (a == b || b == c || a == c)
		ft_error();
	else if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
		ft_putstr(1, "sa\nra");
	else if (a > b && b < c && a < c)
		ft_putstr(1, "sa");
	else if (a < b && b > c && a > c)
		ft_putstr(1, "rra");
	else if (a > b && b > c && a > c)
		ft_putstr(1, "ra\nsa");
	else if (a > b && b < c && a > c)
		ft_putstr(1, "ra");
}

static void	ft_swipe(t_list **stack_a, t_list **stack_b)
{
	ft_cleanlst(stack_a);
	free(stack_b);
	stack_b = NULL;
	exit (0);
}
