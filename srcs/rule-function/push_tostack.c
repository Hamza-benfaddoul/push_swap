/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tostack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:48:09 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/08 18:01:27 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_tostack(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = NULL;
	if (stack_a && *stack_a)
	{
		tmp = (*stack_a)->next;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = tmp;
	}
}
