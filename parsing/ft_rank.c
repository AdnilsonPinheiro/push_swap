/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rank.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:40:50 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/07 16:39:26 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rank(t_list **lst)
{
	t_list	*tmp;
	t_list	*lowest;
	int		i;
	int		count;

	if (!lst || !*lst)
		return ;
	i = 0;
	count = ft_lstsize(lst);
	while (i < count)
	{
		tmp = *lst;
		lowest = NULL;
		while (tmp)
		{
			if (tmp->rank == -1 && (!lowest || tmp->num < lowest->num))
				lowest = tmp;
			tmp = tmp->next;
		}
		if (lowest)
			lowest->rank = i;
		i++;
	}
}
