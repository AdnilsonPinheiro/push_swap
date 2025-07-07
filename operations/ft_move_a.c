/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:23:45 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/07 15:55:06 by adpinhei         ###   ########.fr       */
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
		if (((*src)->rank & bit) == 0)
			ft_push(src, dest);
		else
			ft_fix_a(src, bit);
	}
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
		if ((current->rank & bit) == 0)
			return (1);
		current = current->next;
		counter++;
	}
	return (0);
}

static void	ft_fix_a(t_list **lst, int bit)
{
	int		mid;
	int		zero;
	int		counter;
	t_list	*current;

	mid = ft_mid(lst);
	counter  = 0;
	current = *lst;
	zero = 0;
	while (((current->rank & bit) != 0) && counter < ft_lstsize(lst))
	{
		zero++;
		current = current->next;
		counter++;
	}
	if (zero <= mid)
		ft_rot(lst);
	else
		ft_revrot(lst);
}
