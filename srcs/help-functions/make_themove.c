/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_themove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:29:02 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 11:22:46 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	positive_moves(t_list **stack_a, t_list **stack_b, int i, int j)
{
	while (i && j)
	{
		rotate_stacks(stack_a, stack_b);
		write(1, "rr\n", 3);
		i--;
		j--;
	}
	while (i)
	{
		rotate_stack(stack_a);
		write(1, "ra\n", 3);
		i--;
	}
	while (j)
	{
		rotate_stack(stack_b);
		write(1, "rb\n", 3);
		j--;
	}
}

static void	negative_moves(t_list **stack_a, t_list **stack_b, int i, int j)
{
	while (i && j)
	{
		reverse_rstacks(stack_a, stack_b);
		write(1, "rrr\n", 4);
		i++;
		j++;
	}
	while (i)
	{
		reverse_rstack(stack_a);
		write(1, "rra\n", 4);
		i++;
	}
	while (j)
	{
		reverse_rstack(stack_b);
		write(1, "rrb\n", 4);
		j++;
	}
}

static void	pos_i_neg_j(t_list **stack_a, t_list **stack_b, int i, int j)
{
	while (j)
	{
		reverse_rstack(stack_b);
		write(1, "rrb\n", 4);
		j++;
	}
	while (i)
	{
		rotate_stack(stack_a);
		write(1, "ra\n", 3);
		i--;
	}
}

void	make_themove(t_list **stack_a, t_list **stack_b, int *mv)
{
	if (mv[0] <= 0 && mv[1] <= 0)
		negative_moves(stack_a, stack_b, mv[0], mv[1]);
	else if (mv[0] >= 0 && mv[1] >= 0)
		positive_moves(stack_a, stack_b, mv[0], mv[1]);
	else if (mv[0] <= 0 && mv[1] >= 0)
	{
		while (mv[0])
		{
			reverse_rstack(stack_a);
			write(1, "rra\n", 4);
			mv[0]++;
		}
		while (mv[1])
		{
			rotate_stack(stack_b);
			write(1, "rb\n", 3);
			mv[1]--;
		}
	}
	else if (mv[0] >= 0 && mv[1] <= 0)
		pos_i_neg_j(stack_a, stack_b, mv[0], mv[1]);
	push_tostack(stack_b, stack_a);
	write(1, "pa\n", 3);
}
