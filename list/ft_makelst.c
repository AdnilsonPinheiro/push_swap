/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:03:19 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/08 15:28:27 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_makelst(t_list **lst, int long value)
{
	t_list	*current;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (ft_cleanlst(lst)) ;
	new->num = value;
	new->rank = -1;
	new->prev = NULL;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current->rank = -1;
		current = current->next;
	}
	current->rank = -1;
	current->next = new;
	new->prev = current;
}
