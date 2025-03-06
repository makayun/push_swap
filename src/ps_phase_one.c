#include "push_swap.h"

int ps_average(int *arr, int size)
{
	int i;
	int average;

	i = 0;
	average = 0;
	while (i < size)
	{
		average += arr[i];
		i++;
	}
	return (average / size);
}

void ps_generate_weights(int* arr, const int size) {
	int			j;
	const int	mid = size / 2;

	j = -1;
	while (++j <= mid)
		arr[j] = j * mid / 3;
	while (j < size)
	{
		arr[j] = (size - j) * mid / 3;
		++j;
	}
}

int ps_find_smallest(t_data *data)
{
	int i;
	int smallest;

	i = 0;
	smallest = 0;
	while (i <= data->last_a)
	{
		data->weights[i] += data->a[i] * 2;
		if (data->weights[smallest] > data->weights[i])
			smallest = i;
		++i;
	}
	return (smallest);
}

void	ps_phase_one(t_data *data)
{
	int smallest_weight;

	while (!ps_check_if_sorted(data->a, data->last_a + 1))
	{
		ps_generate_weights(data->weights, data->last_a + 1);
		smallest_weight = ps_find_smallest(data);
		if (smallest_weight == 0)
		{
			while (data->last_b > 0 && data->b[0] < ps_average(data->b, data->last_b + 1))
				ps_execute("rb", data);
			ps_execute("pb", data);
		}
		else if (smallest_weight <= data->last_a / 2)
		{
			if (data->last_b > 0 && data->b[0] < ps_average(data->b, data->last_b + 1))
			ps_execute("rr", data);
			else
			ps_execute("ra", data);
		}
		else
			ps_execute("rra", data);
	}
}
