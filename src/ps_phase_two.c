#include "push_swap.h"
#include <math.h>

void ps_generate_weights2(t_data *data, int* arr, const int size)
{
	int			j;
	const int	mid = size / 2;

	j = -1;
	while (++j <= mid)
		arr[j] = j;
	while (j < size)
	{
		arr[j] = (size - j);
		++j;
	}
	(void)data;
}

int ps_find_smallest2(t_data *data)
{
	int i;
	int smallest;

	i = 0;
	smallest = 0;
	while (i <= data->last_b)
	{
		data->weights[i] += ((data->size - data->b[i])) + (abs(data->b[i] - data->a[0])); // write your own abs()
		if (data->weights[smallest] > data->weights[i]) // if weights are equal - choose the closest to the edge
			smallest = i;
		++i;
	}
	return (smallest);
}

void ps_insert_to_a(t_data *data)
{
	if (data->b[0] > data->a[0] && data->b[0] < data->a[1])
	{
		ps_execute("pa", data);
		ps_execute("sa", data);
		return;
	}
	while (data->a[0] < data->b[0])
		ps_execute("ra", data); // write a function to determine which side to turn
	while (!ps_check_if_sorted(data->a, data->last_a + 1) && data->a[data->last_a] > data->b[0])
		ps_execute("rra", data);
	ps_execute("pa", data);
}

void	ps_phase_two(t_data *data)
{
	int smallest_index;

	while (data->last_b >= 0)
	{
		ps_generate_weights2(data, data->weights, data->last_b + 1);
		smallest_index = ps_find_smallest2(data);
		if (smallest_index == 0)
			ps_insert_to_a(data);
		else if (smallest_index <= data->last_b / 2)
		{
			if (data->a[0] < data->b[smallest_index])
				ps_execute("rr", data);
			else
				ps_execute("rb", data);
		}
		else
		{
			if (!ps_check_if_sorted(data->a, data->last_a + 1) && data->a[data->last_a] > data->b[smallest_index])
				ps_execute("rrr", data);
			else
				ps_execute("rrb", data);
		}
	}
}
