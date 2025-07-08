/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:32:24 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/08 17:48:54 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_isdone(t_list **lst, t_list **b)
{
	t_list	*current;
	int		size;

	size = ft_lstsize(lst);
	current = *lst;
	// while (size > 0)
	// {
	// 	if (current->next && current->num < current->next->num)
	// 	{
	// 		current = current->next;
	// 		size--;
	// 	}
	// 	if (current->next == NULL)
	// 	{
	// 		ft_cleanlst(lst);
	// 		free(b);
	// 		b = NULL;
	// 		ft_putstr(1, "ordered");
	// 		exit (0);
	// 	}
	// }
	while (current->next && current->num < current->next->num)
		current = current->next;
	if (current->next == NULL)
	{
		ft_cleanlst(lst);
		free(b);
		b = NULL;
		ft_putstr(1, "ordered");
		exit (0);
	}
}
