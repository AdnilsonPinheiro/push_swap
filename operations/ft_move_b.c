/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:24:22 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 20:41:53 by adpinhei         ###   ########.fr       */
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
		if (((*src)->num >> (bit + 1) & 1) == 1)
			ft_push(src, dest);
		else
			ft_fix_b(src, bit);
	}
}

static int	ft_one(t_list **lst, int bit)
{
	t_list	*current;

	current = *lst;
	while (current->next != NULL)
	{
		if ((current->num >> (bit - 1) & 1) == 1)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	ft_fix_b(t_list **lst, int bit)
{
	t_list	*current;
	int		one;
	int		mid;

	one = 0;
	mid = ft_mid(lst);
	current = *lst;
	while ((current->num >> (bit - 1) & 1) == 0)
	{
		one++;
		current = current->next;
	}
	if (one < mid)
		ft_rot(lst);
	else
		ft_revrot(lst);
}
