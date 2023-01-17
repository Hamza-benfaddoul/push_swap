/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:40:17 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 08:40:18 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char **str)
{
	short int	i;

	while (*str)
	{
		i = 0;
		while (str[0][i] != '\0')
		{
			if (i == 0 && (**str == '-' || **str == '+'))
				i++;
			if (!ft_isdigit(str[0][i]))
				return (1);
			i++;
		}
		str++;
	}
	return (0);
}
