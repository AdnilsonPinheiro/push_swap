/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:57:52 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/07 16:12:39 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_list **src, t_list **dest)
{

	t_list	*node;

	if (!src || !*src)
		return ;
	node = *src;
	if ((*src)->next)
	{
		*src = (*src)->next;
		(*src)->prev = NULL;
	}
	else if (!(*src)->next)
		*src = NULL;
	if (*dest)
	{
		node->next = *dest;
		(*dest)->prev = node;
	}
	else
		node->next = NULL;
	*dest = node;
}


/*	t_list	*node;

	if (!src || !*src)
		return ;
	node = *src;
	if (!*dest)
	{
		*dest = node;
		*src = (*src)->next;
		(*src)->prev = NULL;
		(*dest)->next = NULL;		
	}
	else
	{
		if ((*src)->next)
			*src = (*src)->next;
		(*src)->prev = NULL;
		node->next = *dest;
		(*dest)->prev = node;
		*dest = node;
	}
	if ((*src)->prev == NULL && (*src)->next == NULL)
	{
		node = *src;
		node->next = *dest;
		(*dest)->prev = node;
		*dest = node;
		*src = NULL;
	}
	if (!(*src)->next)
		*src = NULL;
}*/
