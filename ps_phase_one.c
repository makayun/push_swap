/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_phase_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 04:32:25 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/09 14:15:53 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int ps_weight_one(const int size, const int i)
{
	const int	mid = size / 2;

	if (i <= mid)
		return (i * mid / 3);
	else
		return ((size - i) * mid / 3);
}

int ps_find_smallest(t_data *data)
{
	int			i;
	int			smallest;
	int			index;
	int			current;
	const int	avg = ps_average(&data->pool[data->b_size], data->pool_size - data->b_size);

	i = data->b_size;
	smallest = INT_MAX;
	index = 0;
	while (i < data->pool_size)
	{
		current = ps_weight_one(data->pool_size - data->b_size, i - data->b_size) + data->pool[i] + abs(avg - data->pool[i]);
		if (smallest > current)
		{
			smallest = current;
			index = i - data->b_size;
		}
		++i;
	}
	return (index);
}

void	ps_phase_one(t_data *data)
{
	int				smallest_weight;
	unsigned char	code;

	code = 0;
	while (!ps_is_sorted(&data->pool[data->b_size], data->pool_size - data->b_size))
	{
		smallest_weight = ps_find_smallest(data);
		if (smallest_weight == 0)
		{
			while (data->b_size > 1 && data->pool[data->b_size - 1] < ps_average(data->pool, data->b_size))
				ps_exec(data, RB);
			ps_exec(data, PB);
		}
		else
		{
			code |= RA * (smallest_weight <= (data->pool_size - data->b_size) / 2);
			code |= RB * (data->b_size > 1 && data->pool[data->b_size - 1] < ps_average(data->pool, data->b_size));
			code |= RRA * !(code & RA) * !(code & RB);
			ps_exec(data, code);
		}
		// else if (smallest_weight <= (data->pool_size - data->b_size) / 2)
		// {
		// 	if (data->b_size > 1 && data->pool[data->b_size - 1] < ps_average(data->pool, data->b_size))
		// 		ps_exec(data, RR);
		// 	else
		// 		ps_exec(data, RA);
		// }
		// else
		// 	ps_exec(data, RRA);
	}
}

