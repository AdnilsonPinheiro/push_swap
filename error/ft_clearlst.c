/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:16:27 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 19:24:41 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clearlst(t_list **lst)
{
	t_list	*node;
	t_list	*temp;

	node = *lst;
	while (node->next != NULL)
		node = node->next;
	while (node != *lst)
	{
		temp = node->prev;
		temp->next = NULL;
		node->prev = NULL;
		node = temp;
	}
	node->prev = NULL;
	node = NULL;
	*lst = NULL;
	lst = NULL;
}
