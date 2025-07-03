/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:23:45 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 18:24:16 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_zero(t_list **lst, int bit);
static void	ft_fix_a(t_list **lst, int bit);

void	ft_move_a(t_list **src, t_list **dest, int bit)
{
	if (!src || !*src)
		return ;
	while (ft_zero(src, bit))
	{
		if (((*src)->rank >> bit & 1) == 0)
			ft_push(src, dest);
		else
			ft_fix_a(src, bit);
	}
	// ft_putstr(1, "move_a\n");
}

static int	ft_zero(t_list **lst, int bit)
{
	t_list	*current;
	int		counter;

	counter = 0;
	if (!lst || !*lst)
		return (0);
	current = *lst;
	while (counter < ft_lstsize(lst))
	{
		if ((current->rank >> bit & 1) == 0)
			return (1);
		current = current->next;
		counter++;
	}
	return (0);
}

static void	ft_fix_a(t_list **lst, int bit)
{
	int		mid;
	int		one;
	int		counter;
	t_list	*current;

	mid = ft_mid(lst);
	counter  = 0;
	current = *lst;
	one = 0;
	while (((current->rank >> bit & 1) == 1) && counter < ft_lstsize(lst))
	{
		one++;
		current = current->next;
	}
	if (one <= mid)
		ft_rot(lst);
	else
		ft_revrot(lst);
}
