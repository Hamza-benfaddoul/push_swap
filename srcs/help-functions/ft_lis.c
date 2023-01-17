/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:17:23 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/14 18:56:22 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*get the the index that has max lenght*/
size_t	get_index(int *lenght, size_t size)
{
	size_t	i;
	size_t	temp;
	int		tmp;

	i = 0;
	tmp = INT_MIN;
	while (i < size)
	{
		if (lenght[i] > tmp)
		{
			tmp = lenght[i];
			temp = i;
		}
		i++;
	}
	return (temp);
}

/*return lis */
ssize_t	*get_lis(int *arry, int *lenght, int *sub_sq, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	ssize_t	*tmp;

	tmp = NULL;
	i = 1;
	j = get_index(lenght, size);
	k = lenght[j];
	tmp = (ssize_t *)malloc(sizeof(ssize_t) * k + 1);
	if (!tmp)
		return (NULL);
	tmp[0] = k;
	while (k)
	{
		tmp[i] = arry[j];
		j = sub_sq[j];
		i++;
		k--;
	}
	return (tmp);
}

/*calucalte lenght of lis for each number*/
void	get_lenghtlis(int *arry, int *lenght, int *sub_sq, size_t size)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arry[j] < arry[i])
			{
				if (lenght[i] <= lenght[j] + 1)
				{
					lenght[i] = lenght[j] + 1;
					sub_sq[i] = j;
				}
			}
			j++;
		}
		i++;
	}
}

/*allocate memory and call funtion to get lis*/
ssize_t	*ft_lis(t_list *lst, size_t size)
{
	size_t	i;
	int		*arry;
	int		*lenght;
	int		*sub_sq;
	ssize_t	*lis;

	i = 0;
	lis = NULL;
	arry = add_toarry(lst, size);
	lenght = (int *)malloc(sizeof(int) * size);
	sub_sq = (int *)malloc(sizeof(int) * size);
	if (!arry || !lenght || !sub_sq)
		return (NULL);
	while (i < size)
		lenght[i++] = 1;
	get_lenghtlis(arry, lenght, sub_sq, size);
	lis = get_lis(arry, lenght, sub_sq, size);
	return (free(lenght), free(arry), free(sub_sq), lis);
}
