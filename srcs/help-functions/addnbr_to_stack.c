/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addnbr_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:40:05 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 08:40:05 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_double_nbr(t_list *stack, int nbr)
{
	while (stack)
	{
		if (nbr == *(int *)stack->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	addnbr_to_stack(t_list **stack, char **ar)
{
	t_list	*node;
	int		*tmp;

	node = NULL;
	tmp = NULL;
	while (*ar)
	{
		tmp = (int *)malloc(sizeof(int));
		if (!tmp)
			return (1);
		*tmp = ft_atoi(*ar);
		if (check_double_nbr(*stack, *tmp))
			return (1);
		node = ft_lstnew(tmp);
		if (!node)
			return (1);
		ft_lstadd_back(stack, node);
		ar++;
	}
	return (0);
}
