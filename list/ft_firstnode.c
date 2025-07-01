/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:25:26 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 18:15:29 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_firstnode(t_list **lst, int long value)
{
	*lst = malloc(sizeof(t_list));
	if (!*lst)
		return ;
	(*lst)->num = value;
	(*lst)->prev = NULL;
	(*lst)->next = NULL;
}
