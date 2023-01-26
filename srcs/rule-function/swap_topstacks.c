/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_topstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:06:26 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/26 02:08:05 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_topstacks(t_list **stack_a, t_list **stack_b)
{
	swap_topstack(stack_a);
	swap_topstack(stack_b);
}
