/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:38:31 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 19:30:29 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clean_b(t_list **src, t_list **dest)
{
	t_list	*current;
	int		size;

	current = *src;
	size = 0;
	while (current->next != NULL)
	{
		*src = (*src)->next;
		current->prev = NULL;
		current->next = *dest;
		*dest = current;
		current = *src;
	}
	(*src)->next = *dest;
	(*dest)->prev = *src;
	*dest = (*dest)->prev;
	*src = NULL;
	src = NULL;
}
