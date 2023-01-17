/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:08:57 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/14 18:34:53 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_move(int *arry, int nbr, size_t size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	if (nbr < arry[0] && nbr < arry[size - 1])
		return (0);
	while (i < size / 2)
	{
		if (nbr > arry[i] && nbr < arry[i +1])
			return (i);
		if (nbr > arry[j - 1] && nbr < arry[j])
			return (-j);
		i++;
		j--;
	}
}
