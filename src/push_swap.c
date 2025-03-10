#include "push_swap.h"



void push_swap(t_data *data)
{
		ps_phase_one(data);
		ps_phase_two(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.size = argc - 1;
	if (data.size <= 1)
		return (1);
	data.a = (int *)malloc(data.size * sizeof(int));
	data.b = (int *)malloc(data.size * sizeof(int));
	data.weights = (int *)malloc(data.size * sizeof(int));
	if (!data.a || !data.b || !data.weights)
		ps_exit(&data, "Memory allocation error", 1);
	ps_initialize(argv, &data);
	push_swap(&data);
	ps_exit(&data, "", 0);
}
