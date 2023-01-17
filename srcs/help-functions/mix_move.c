/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:49:51 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/14 18:52:25 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mix_move(int a, int b, int *mv)
{
	if (mv[0] <= 0 && mv[1] <= 0)
	{
		if (get_abs(a) + get_abs(b) < get_abs(get_small(mv[0], mv[1])))
		{
			mv[0] = a;
			mv[1] = b;
		}
	}
	else if (mv[0] >= 0 && mv[1] >= 0)
	{
		if (get_abs(a) + get_abs(b) < (size_t)get_bigone(mv[0], mv[1]))
		{
			mv[0] = a;
			mv[1] = b;
		}
	}
	else
	{
		if (get_abs(a) + get_abs(b) < get_abs(mv[0]) + get_abs(mv[1]))
		{
			mv[0] = a;
			mv[1] = b;
		}
	}
}
