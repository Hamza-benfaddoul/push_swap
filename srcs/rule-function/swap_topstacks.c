#include "push_swap.h"

void	swap_topstacks(t_list **stack_a, t_list **stack_b)
{
    swap_topstack(stack_a);
    swap_topstack(stack_b);
}