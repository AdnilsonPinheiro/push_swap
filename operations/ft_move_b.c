/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:24:22 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 18:32:58 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_one(t_list **lst, int bit);
static void	ft_fix_b(t_list **lst, int bit);

void	ft_move_b(t_list **src, t_list **dest, int bit)
{
	if (!src || !*src)
		return ;
	while (ft_one(src, bit))
	{
		if (((*src)->rank >> (bit + 1) & 1) == 1)
			ft_push(src, dest);
		else
			ft_fix_b(src, bit);
	}
	// ft_putstr(1, "move_b\n");
}

static int	ft_one(t_list **lst, int bit)
{
	t_list	*current;
	int		counter;

	counter = 0;
	current = *lst;
	while (counter < ft_lstsize(lst))
	{
		if ((current->rank >> (bit + 1) & 1) == 1)
			return (1);
		current = current->next;
		counter++;
	}
	return (0);
}

static void	ft_fix_b(t_list **lst, int bit)
{
	t_list	*current;
	int		one;
	int		mid;
	int		counter;

	one = 0;
	counter = 0;
	mid = ft_mid(lst);
	current = *lst;
	while (((current->rank >> (bit + 1) & 1) == 0) && counter < ft_lstsize(lst))
	{
		one++;
		current = current->next;
		counter++;
	}
	if (one <= mid)
		ft_rot(lst);
	else
		ft_revrot(lst);
}
