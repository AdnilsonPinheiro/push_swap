/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:57:52 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 18:01:04 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*node;

	if (!src || !*src)
		return ;
	node = *src;
	if (!*dest)
	{
		*dest = node;
		*src = (*src)->next;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;		
	}
	else
	{
		*src = (*src)->next;
		(*src)->prev = NULL;
		node->next = *dest;
		(*dest)->prev = node;
		node->prev = NULL;
		*dest = node;
	}
}
