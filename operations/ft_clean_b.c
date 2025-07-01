/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:38:31 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 14:06:56 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clean_b(t_list **src, t_list **dest)
{
	t_list	*node;
	int		flag;

	flag = 1;
	node = *src;
	if (!src || !*src)
		return ;
	while (!ft_isempty(src))
	{
		node->prev = (*dest)->prev;
		node->next = *dest;
		(*dest)->prev = node;
		*dest = node;
	}
}
