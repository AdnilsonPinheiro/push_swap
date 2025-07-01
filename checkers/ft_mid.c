/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:49:50 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/01 21:29:04 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_mid(t_list **lst)
{
	if (ft_lstsize(lst) % 2 == 0)
		return (ft_lstsize(lst) / 2);
	else
		return ((ft_lstsize(lst) + 1) / 2);
}