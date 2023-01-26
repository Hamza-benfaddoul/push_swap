/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:17:23 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/26 01:32:05 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*get the the index that has max length*/
static int	get_index(int *length, size_t size)
{
	size_t	i;
	int		temp;
	int		tmp;

	i = 0;
	tmp = INT_MIN;
	while (i < size)
	{
		if (length[i] > tmp)
		{
			tmp = length[i];
			temp = i;
		}
		i++;
	}
	return (temp);
}

/*return lis */
static int	*get_lis(int *arry, int *length, int *sub_sq, size_t size)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	tmp = NULL;
	i = 1;
	j = get_index(length, size);
	k = length[j];
	tmp = (int *)malloc(sizeof(int) * k + 1);
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

/*calucalte length of lis */
static void	get_length_oflis(int *arry, int *length, int *sub_sq, size_t size)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if ((arry[j] < arry[i]) && (length[i] < length[j] + 1))
			{
				length[i] = length[j] + 1;
				sub_sq[i] = j;
			}
			j++;
		}
		i++;
	}
}

/*allocate memory and call funtion to get lis*/
int	*ft_lis(t_list *lst, size_t size)
{
	size_t	i;
	int		*lis;
	int		*arry;
	int		*length;
	int		*sub_sq;

	i = 0;
	lis = NULL;
	arry = add_toarry(lst, size);
	if (!arry)
		return (NULL);
	length = (int *)malloc(sizeof(int) * size);
	if (!length)
		return (free(arry), NULL);
	sub_sq = (int *)malloc(sizeof(int) * size);
	if (!sub_sq)
		return (free(arry), free(length), NULL);
	while (i < size)
		length[i++] = 1;
	get_length_oflis(arry, length, sub_sq, size);
	lis = get_lis(arry, length, sub_sq, size);
	return (free(length), free(arry), free(sub_sq), lis);
}
