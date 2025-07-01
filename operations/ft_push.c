/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:57:52 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 21:33:03 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*node;

	if (!src || !*src || (*src)->next == NULL)
		return ;
	node = *src;
	if (!*dest)
	{
		*dest = node;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
		if ((*src)->next)
			(*src)->next->prev = NULL;
		*src = (*src)->next;
	}
	else
	{
		node->next = *dest;
		(*dest)->prev = node;
		node->prev = NULL;
		*dest = node;
	}
}
