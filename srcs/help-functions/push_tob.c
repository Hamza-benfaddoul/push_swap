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

static int	binarySearch(int *arr, int low, int high, int x)
{
	int	mid;

    mid = low + (high - low) / 2;
    if (high >= low) {
        if (arr[mid] == x)
            return (1);
        if (arr[mid] < x)
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);
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
	else
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

void	push_tob(int *lis, t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (!binarySearch(lis, 1, *lis, *(int *)tmp->content))
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
