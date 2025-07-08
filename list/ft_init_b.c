/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:28:06 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/08 14:37:52 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	**ft_init_b(t_list **lst)
{
	lst = malloc(sizeof(t_list *));
	if (!lst)
		return (NULL);
	*lst = NULL;
	return (lst);
}
