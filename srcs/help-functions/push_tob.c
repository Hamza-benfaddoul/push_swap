/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:22:49 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 10:48:53 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker(int *a, ssize_t *lis)
{
	int	i;

	i = 1;
	while (i <= lis[0])
	{
		if (*a == lis[i])
			return (1);
		i++;
	}
	return (0);
}

static void	make_rotate(t_list **stack_a, size_t i, size_t size)
{
	if (i <= size / 2)
	{
		while (i)
		{
			rotate_stack(stack_a);
			write(1, "ra\n", 3);
			i--;
		}
	}
	else if (i > size / 2)
	{
		i = size - i;
		while (i)
		{
			reverse_rstack(stack_a);
			write(1, "rra\n", 4);
			i--;
		}
	}
}

void	push_tob(ssize_t *lis, t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (!checker(tmp->content, lis))
		{
			make_rotate(stack_a, i, ft_lstsize(*stack_a));
			push_tostack(stack_a, stack_b);
			i = 0;
			write(1, "pb\n", 3);
			tmp = *stack_a;
			continue ;
		}
		tmp = tmp->next;
		i++;
	}
}
