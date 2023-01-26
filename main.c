/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:33:57 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/01/26 02:31:26 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *prt)
{
	free(prt);
	prt = NULL;
}

void	free_all(char **split)
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
	if (ac == 4)
		tree_sort(&stack_a);
	else
		push_swap(&stack_a, ft_lstsize(stack_a));
	return (ft_lstclear(&stack_a, del), 0);
}
