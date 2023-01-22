/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:54:55 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/18 02:00:56 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../get_nextline/get_next_line.h"

static void	del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

static int	do_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (!ft_strncmp("sa\n", move, 3))
		swap_topstack(stack_a);
	else if (!ft_strncmp("sb\n", move, 3))
		swap_topstack(stack_b);
	else if (!ft_strncmp("ss\n", move, 3))
		swap_topstacks(stack_a, stack_b);
	else if (!ft_strncmp("pa\n", move, 3))
		push_tostack(stack_b, stack_a);
	else if (!ft_strncmp("pb\n", move, 3))
		push_tostack(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", move, 3))
		rotate_stack(stack_a);
	else if (!ft_strncmp("rb\n", move, 3))
		rotate_stack(stack_b);
	else if (!ft_strncmp("rr\n", move, 3))
		rotate_stacks(stack_a, stack_b);
	else if (!ft_strncmp("rra\n", move, 4))
		reverse_rstack(stack_a);
	else if (!ft_strncmp("rrb\n", move, 4))
		reverse_rstack(stack_b);
	else if (!ft_strncmp("rrr\n", move, 4))
		reverse_rstacks(stack_a, stack_b);
	else
		return (1);
	return (0);
}

void	ft_checker(t_list **stack_a)
{
	t_list	*stack_b;
	char	*move;
	size_t	s;

	s = ft_lstsize(*stack_a);
	stack_b = NULL;
	move = get_next_line(0);
	while (move)
	{
		if (s == 1 || ft_strlen(move) > 4 || do_move(stack_a, &stack_b, move))
		{
			ft_lstclear(stack_a, del);
			ft_lstclear(&stack_b, del);
			write (2, "Error\n", 6);
			exit(1);
		}
		move = get_next_line(0);
	}
	if (stack_b || isstack_sorted(*stack_a))
	{
		ft_lstclear(&stack_b, del);
		write(1, "KO\n", 3);
	}
	else
		write (1, "OK\n", 3);
}
