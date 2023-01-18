#include "push_swap.h"

int	isstack_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}