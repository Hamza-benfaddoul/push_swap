/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sorte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:42:25 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/26 01:42:25 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tree_sort(t_list **stack)
{
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
	{
		write(1, "sa\n", 3);
		swap_topstack(stack);
	}
	else if (*(int *)(*stack)->next->content
		> *(int *)(*stack)->next->next->content)
	{
		write(1, "rra\n", 4);
		reverse_rstack(stack);
	}
	else
		return ;
	tree_sort(stack);
}
