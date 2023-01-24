/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 08:39:05 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 11:07:11 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "../../libft/libft.h"
# include <stdio.h>

void	push_swap(t_list **stack_a, size_t size);
void	push_tostack(t_list **stack_a, t_list **stack_b);
void	swap_topstacks(t_list **stack_a, t_list **stack_b);
void	swap_topstack(t_list **stack);
void	rotate_stacks(t_list **stack_a, t_list **stack_b);
void	rotate_stack(t_list **stack);
void	reverse_rstacks(t_list **stack_a, t_list **stack_b);
void	reverse_rstack(t_list **stack);
int		*add_toarry(t_list *lst, size_t size);
void	quicksort(int *number, ssize_t first, ssize_t last);
int		check_nbr(int *arry, size_t size);
int		*ft_lis(t_list *lst, size_t size);
void	push_tob(int *lis, t_list **stack_a, t_list **stack_b);
int		*get_bestmove(int *arry, t_list *stack_b, size_t size_a, size_t size_b);
void	make_themove(t_list **stack_a, t_list **stack_b, int *mv);
size_t	get_abs(int nbr);
void	positve_move(int a, int b, int *mv);
void	negative_move(int a, int b, int *mv);
int		get_small(int x, int y);
int		get_bigone(int x, int y);
void	mix_move(int a, int b, int *mv);
int		addnbr_to_stack(t_list **stack, char **ar);
int		check_error(char **str);
void	ft_checker(t_list **stack_a);
int		isstack_sorted(t_list *stack);
void	tree_sort(t_list **stack);

#endif
