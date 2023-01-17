/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_themove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:29:02 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/14 18:48:59 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_themove(t_list **stack_a, t_list **stack_b, int *move)
{
	int	i;
	int	j;

	i = move[0];
	j = move[1];
	if (i <= 0 && j <= 0)
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
	else if (i >= 0 && j >= 0)
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
	else if (i <= 0 && j >= 0)
	{
		while (i)
		{
			reverse_rstack(stack_a);
			write(1, "rra\n", 4);
			i++;
		}
		while (j)
		{
			rotate_stack(stack_b);
			write(1, "rb\n", 3);
			j--;
		}
	}
	else if (i >= 0 && j <= 0)
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
	push_tostack(stack_b, stack_a);
	write(1, "pa\n", 3);
}
