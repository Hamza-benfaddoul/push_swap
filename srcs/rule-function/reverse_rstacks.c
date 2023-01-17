/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rstacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:52:16 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/02 14:38:09 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rstacks(t_list **stack_a, t_list **stack_b)
{
	reverse_rstack(stack_a);
	reverse_rstack(stack_b);
}
