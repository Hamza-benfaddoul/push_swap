/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:45:53 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/02 14:33:05 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	if (stack && *stack && (*stack)->next)
	{
		tmp = *stack;
		ft_lstadd_back(stack, *stack);
		*stack = (*stack)->next;
		tmp->next = NULL;
	}
}
