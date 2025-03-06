#include "push_swap.h"

void	ps_exit(t_data *data, char *message, int code)
{
	free (data->a);
	free (data->b);
	free (data->weights);
	if (message && *message)
		ft_printf ("%s\n", message);
	exit (code);
}

int ps_check_if_sorted(int *stack, int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (stack[i] <= stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	ps_move_up(int *stack, int last)
{
	int	i;

	i = 0;
	while (i < last)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[last] = 0;
}

void	ps_move_down(int *stack, int last)
{
	int	i;

	i = last;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
}
