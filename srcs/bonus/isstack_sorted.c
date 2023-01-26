/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstack_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:04:53 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/26 02:05:18 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isstack_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}
