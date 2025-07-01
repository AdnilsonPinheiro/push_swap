/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:23:45 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 21:43:16 by adpinhei         ###   ########.fr       */
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
		ft_printlst(src, "stack");
		if (((*src)->rank >> bit & 1) == 0)
			ft_push(src, dest);
		else
			ft_fix_a(src, bit);
	}
}

static int	ft_zero(t_list **lst, int bit)
{
	t_list	*current;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	while (current->next != NULL)
	{
		if ((current->rank >> bit & 1) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	ft_fix_a(t_list **lst, int bit)
{
	int		mid;
	int		one;
	t_list	*current;

	mid = ft_mid(lst);
	current = *lst;
	one = 0;
	while ((current->rank >> bit & 1) == 1)
	{
		one++;
		current = current->next;
	}
	if (one < mid)
		ft_rot(lst);
	else
		ft_revrot(lst);
}
