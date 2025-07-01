/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:03:19 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 17:30:43 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_makelst(t_list **lst, int long value)
{
	t_list	*current;
	t_list	*new;

	current = *lst;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->num = value;
	new->prev = current;
	new->next = NULL;
}
