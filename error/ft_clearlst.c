/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:16:27 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 21:45:54 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clearlst(t_list **lst)
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	while (current != *lst)
	{
		temp = current->prev;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = temp;
	}
	free (current);
	free (lst);
}
