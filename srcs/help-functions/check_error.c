/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:40:17 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/26 01:47:03 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_max_min_int(char *str)
{
	size_t	result;
	int		sign;

	result = 0;
	sign = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((sign && result > 2147483648) || (!sign && result > 2147483647))
		return (1);
	return (0);
}

int	check_error(char **str)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (*(*str + i) != '\0' && i < 11)
		{
			if (i == 0 && (**str == '-' || **str == '+'))
				i++;
			if (!ft_isdigit(*(*str + i)))
				return (1);
			i++;
		}
		if (ft_strlen(*str) > 11)
			return (1);
		else if (ft_strlen(*str) >= 10 && check_max_min_int(*str))
			return (1);
		str++;
	}
	return (0);
}
