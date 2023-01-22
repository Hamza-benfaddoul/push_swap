/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:43:06 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/17 22:52:18 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del(void *prt)
{
	free(prt);
	prt = NULL;
}

static void	free_all(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static void	p_error(void)
{
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**tmp;
	int		i;

	tmp = NULL;
	stack_a = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		tmp = ft_split(av[i++], ' ');
		if (!tmp || !(*tmp))
			return (ft_lstclear(&stack_a, del), p_error(), 1);
		if (check_error(tmp))
			return (ft_lstclear(&stack_a, del), free_all(tmp), p_error(), 1);
		if (addnbr_to_stack(&stack_a, tmp))
			return (ft_lstclear(&stack_a, del), free_all(tmp), p_error(), 1);
		free_all(tmp);
	}
	ft_checker(&stack_a);
	return (ft_lstclear(&stack_a, del), 0);
}