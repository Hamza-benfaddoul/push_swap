#include "push_swap.h"

void	swap_topstack(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}