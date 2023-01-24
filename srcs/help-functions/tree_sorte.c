#include "push_swap.h"

void tree_sort(t_list **stack)
{
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
	{
		write(1, "sa\n", 3);
		swap_topstack(stack);
	}
	else if (*(int *)(*stack)->content > *(int *)(*stack)->next->next->content)
	{
		write(1, "rra\n", 4);
		reverse_rstack(stack);
	}
	else
		return ;
	tree_sort(stack);
}