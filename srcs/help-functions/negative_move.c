/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:19:55 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/14 18:21:58 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	negative_move(int a, int b, int *mv)
{
	if (mv[0] >= 0 && mv[1] >= 0)
	{
		if ((size_t)get_bigone(mv[0], mv[1]) > get_abs(get_small(a, b)))
		{
			mv[0] = a;
			mv[1] = b;
		}
	}
	else if (mv[0] <= 0 && mv[1] <= 0)
	{
		if (get_small(a, b) > get_small(mv[0], mv[1]))
		{
			mv[0] = a;
			mv[1] = b;
		}
	}
	else
	{
		if (get_abs(get_small(a, b)) < get_abs(mv[0]) + get_abs(mv[1]))
		{
			mv[0] = a;
			mv[1] = b;
		}
	}
}
