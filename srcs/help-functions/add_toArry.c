/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_toArry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:10:46 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 08:42:25 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*add_toarry(t_list *lst, size_t size)
{
	int		*arry;
	size_t	i;

	i = 0;
	arry = (int *)malloc(sizeof(int) * size);
	if (!arry || !size)
		return (NULL);
	while (i < size)
	{
		arry[i] = *(int *)lst->content;
		lst = lst->next;
		i++;
	}
	return (arry);
}
