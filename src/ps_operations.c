#include "push_swap.h"

void	ps_swap(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	ps_push(int *stack_from, int *stack_to, int last_from, int last_to)
{
	ps_move_down(stack_to, last_to);
	stack_to[0] = stack_from[0];
	ps_move_up(stack_from, last_from);

}

void	ps_rotate(int *stack, int last)
{
	int	temp;

	temp = stack[0];
	ps_move_up(stack, last);
	stack[last] = temp;
}

void	ps_reverse_rotate(int *stack, int last)
{
	int	temp;

	temp = stack[last];
	ps_move_down(stack, last);
	stack[0] = temp;
}
