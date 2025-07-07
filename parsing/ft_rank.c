/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rank.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:40:50 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/04 18:08:36 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int long	ft_max(t_list **lst);
static int long	ft_min(t_list **lst);
static int long	ft_nextmin(t_list **lst, int long nbr);
static void		ft_putrank(t_list **lst, int long value, int rnk);

void	ft_rank(t_list **lst)
{
	int long	max;
	int long	min;
	int			i;

	max = ft_max(lst);
	ft_putrank(lst, max, ft_lstsize(lst));
	min = ft_min(lst);
	ft_putrank(lst, min, 0);
	i = 1;
	while (min < max)
	{
		min = ft_nextmin(lst, min);
		ft_putrank(lst, min, i);
		//printf("rank %i\n", i);
		i++;
	}
}
static int long	ft_max(t_list **lst)
{
	t_list	*current;
	int		max;

	current = *lst;
	max = current->num;
	while (current->next != NULL)
	{
		if (current->num > max)
			{
				max = current->num;
				current = *lst;
			}
		else
			current = current->next;
	}
	if (current->num > max)
		max = current->num;
	return (max);
}

static int long	ft_min(t_list **lst)
{
	t_list	*current;
	int		min;

	current = *lst;
	min = current->num;
	while (current->next != NULL)
	{
		if (current->num < min)
			{
				min = current->num;
				current = *lst;
			}
		else
			current = current->next;
	}
	if (current->num < min)
		min = current->num;
	return (min);
}

static int long	ft_nextmin(t_list **lst, int long nbr)
{
	t_list		*current;
	int long	new;

	current = *lst;
	new = ft_max(lst);
	while (current->next != NULL)
	{
		if (current->num > nbr && current->num < new)
		{
			new = current->num;
			current = *lst;
		}
		else
			current = current->next;
	}
	if (current->num > nbr && current->num < new)
		new = current->num;
	return (new);
}

static void		ft_putrank(t_list **lst, int long value, int rnk)
{
	t_list	*current;

	current = *lst;
	while (current->next != NULL)
	{
		if (current->num == value)
			current->rank = rnk;
		current = current->next;
	}
	if (current->num == value)
		current->rank = rnk;
}
