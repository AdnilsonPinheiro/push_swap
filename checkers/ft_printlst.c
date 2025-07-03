/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:13:27 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 15:16:39 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_printlst(t_list **lst, char *name)
{
	t_list	*current;

	if (!lst || !*lst)
	{
		printf("%s\n", name);
		ft_putstr(1, "stack is empty\n");
		return;
	}
	current = *lst;
	printf("%s ", name);
	// while (current->next != NULL)
	// {
	// 	printf("%li ", current->num);
	// 	current = current->next;
	// }
	// printf("%li ", current->num);
	// printf("\n");
	current = *lst;
	while (current->next != NULL)
	{
		printf("%u ", current->rank);
		current = current->next;
	}
	printf("%u ", current->rank);
	printf("\n");
}
