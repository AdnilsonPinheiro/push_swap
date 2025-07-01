/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:55:24 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 20:57:03 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list **lst)
{
	int		size;
	t_list	*current;

	if (!lst || !*lst)
		return (0);
	size = 0;
	current = *lst;
	if (current->next == NULL)
		return (1);
	while (current->next != NULL)
	{
		current = current->next;
		size++;
	}
	return (size);
}
