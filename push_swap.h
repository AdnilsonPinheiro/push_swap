/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:46:56 by adpinhei          #+#    #+#             */
/*   Updated: 2025/07/03 18:59:07 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*libraries*/
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	int long		num;
	unsigned int	rank;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

/*error function*/
void		ft_clearlst(t_list **lst);
void		ft_error(void);

/*list functions*/
void		ft_makelst(t_list **lst, int long	value);
void		ft_firstnode(t_list **lst, int long value);
int			ft_lstsize(t_list **lst);

/*checkers*/
void		ft_repetition(t_list **lst);
void		ft_printlst(t_list **lst, char *name);
void		ft_isdone(t_list **master, t_list **serv);
int			ft_mid(t_list **lst);

/*parsing functions*/
void		ft_rank(t_list **lst);

int long	ft_atol(char *str);

/*operations functions*/
void		ft_sort(t_list **stack_a);
void		ft_move_a(t_list **src, t_list **dest, int bit);
void		ft_move_b(t_list **src, t_list **dest, int bit);
void		ft_push(t_list **src, t_list **dest);
void		ft_rot(t_list **stack);
void		ft_revrot(t_list **stack);
void		ft_clean_b(t_list **src, t_list **dest);

/*output*/
void		ft_putstr(int fd, char *str);

#endif