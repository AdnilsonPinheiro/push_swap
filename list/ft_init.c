/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:48:08 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/07 16:43:08 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	**ft_init(t_list **lst)
{
	lst = malloc(sizeof(t_list*));
	if (!lst)
		return (NULL);
	*lst = malloc(sizeof(t_list));
	if(!*lst)
	{
		free(lst);
		return (NULL);
	}
	(*lst)->prev = NULL;
	(*lst)->next = NULL;
	return (lst);
}
