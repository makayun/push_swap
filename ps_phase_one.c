/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_phase_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 04:32:25 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 19:30:43 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_average(const int *arr, const int size)
{
	int	i;
	int	average;

	i = 0;
	average = 0;
	while (i < size)
	{
		average += arr[i];
		i++;
	}
	return (average / size);
}

long	ps_count_steps_one(const long size, const long i)
{
	const long	mid = (long)size / 2;

	if (i <= mid)
		return (i * mid / 3);
	else
		return ((size - i) * mid / 3);
}

int	ps_find_smallest(const int *pool, const int b_size, const int pool_size)
{
	int			i;
	int			index;
	long		smallest;
	long		current;
	const int	avg = ps_average(&pool[b_size], pool_size - b_size);

	i = b_size;
	smallest = LONG_MAX;
	index = 0;
	while (i < pool_size)
	{
		current = ps_count_steps_one(pool_size - b_size, i - b_size);
		current += pool[i] + abs(avg - pool[i]);
		if (smallest > current)
		{
			smallest = current;
			index = i - b_size;
		}
		++i;
	}
	return (index);
}

void	ps_phase_one(t_data *data, int *pool, int *b_size, const int pool_size)
{
	int	smallest_weight;

	while (!ps_is_sorted(&pool[*b_size], pool_size - *b_size))
	{
		smallest_weight = ps_find_smallest(pool, *b_size, pool_size);
		if (smallest_weight == 0)
		{
			while (*b_size > 1 && pool[*b_size - 1] < ps_average(pool, *b_size))
				ps_exec(data, RB);
			ps_exec(data, PB);
		}
		else if (smallest_weight <= (pool_size - *b_size) / 2)
		{
			if (*b_size > 1 && pool[*b_size - 1] < ps_average(pool, *b_size))
				ps_exec(data, RR);
			else
				ps_exec(data, RA);
		}
		else
			ps_exec(data, RRA);
	}
}
