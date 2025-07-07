/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:38:31 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/07 15:55:01 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clean_b(t_list **src, t_list **dest)
{
	int	size;

	size = ft_lstsize(src);
	while (size > 0)
	{
		ft_push(src, dest);
		// ft_printlst(dest, "A");
		// ft_printlst(src, "B");
		size--;
	}

	/*t_list	*current;
	int		size;

	if (!src || !*src)
		return ;
	size = ft_lstsize(src);
	if (!*dest)
	{
		current = *src;
		*src = (*src)->next;
		(*src)->prev = NULL;
		*dest = current;
		(*dest)->next = NULL;
		*src = NULL;
	}

	while (size > 1)
	{
		current = *src;
		*src = (*src)->next;
		(*src)->prev = NULL;
		current->next = *dest;
		(*dest)->prev = current;
		*dest = current;
		size--;
	}
	current = *src;
	current->next = *dest;
	(*dest)->prev = current;
	*dest = current;
	*src = NULL;
	*/
}
