/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:22:49 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 09:43:50 by hbenfadd         ###   ########.fr       */
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

void	push_tob(ssize_t *lis, t_list **stack_a, t_list **stack_b)
{
	size_t	i;
	size_t	size;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (!checker(tmp->content, lis))
		{
			size = ft_lstsize(*stack_a);
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
			push_tostack(stack_a, stack_b);
			write(1, "pb\n", 3);
			tmp = *stack_a;
			continue ;
		}
		tmp = tmp->next;
		i++;
	}
}
