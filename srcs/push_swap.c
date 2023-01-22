/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:18:01 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 09:43:04 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_indexminnbr(t_list *stack, size_t size)
{
	size_t	i;
	int		tmp;
	size_t	index;

	tmp = INT_MAX;
	i = 0;
	index = i;
	while (stack)
	{
		if (tmp > *(int *)stack->content)
		{
			tmp = *(int *)stack->content;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	if (index > size / 2)
		return (-(size - index));
	return (index);
}

static void	final_sort(t_list **stack_a, size_t size)
{
	int	i;

	i = get_indexminnbr(*stack_a, size);
	while (i)
	{
		if (i < 0)
		{
			reverse_rstack(stack_a);
			write(1, "rra\n", 4);
			i++;
		}
		else if (i > 0)
		{
			rotate_stack(stack_a);
			write(1, "ra\n", 3);
			i--;
		}
	}
}

static	int *longest_is(t_list **stack, size_t size, int i)
{
	int	k;
	int *tmp;

	k = i * -1;
	tmp = NULL;
	if (!i)
		return (ft_lis(*stack, size));
	while (i || k)
	{
		if (i < 0)
		{
			while (i++)
				reverse_rstack(stack);
		}
		else if (i > 0)
		{
			while (i--)
				rotate_stack(stack);
		}
		if (k)
			tmp = ft_lis(*stack, size);
		i = k;
		k = 0;
	}
	return (tmp);
}

void	push_swap(t_list **stack_a, size_t size)
{
	t_list	*stack_b;
	int		*tmp;
	int		*m;

	stack_b = NULL;
	tmp = longest_is(stack_a, size, get_indexminnbr(*stack_a, size));
	if (!tmp)
		return ;
	if (*tmp != (int)size)
		push_tob(tmp, stack_a, &stack_b);
	free(tmp);
	while (ft_lstsize(stack_b))
	{
		tmp = add_toarry(*stack_a, ft_lstsize(*stack_a));
		if (!tmp)
			return ;
		m = get_bestmove(tmp, stack_b, ft_lstsize(*stack_a), ft_lstsize(stack_b));
		free(tmp);
		if (!m)
			return ;
		make_themove(stack_a, &stack_b, m);
		free(m);
	}
	final_sort(stack_a, ft_lstsize(*stack_a));
}
