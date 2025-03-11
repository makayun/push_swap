/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_phase_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:52:47 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 20:31:23 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

long	ps_count_steps_two(const long size, const long i)
{
	const long	mid = (long)size / 2;

	if (i >= mid)
		return (size - i - 1);
	else
		return (i + 1);
}

int ps_find_smallest2(t_data *data)
{
	int		i;
	int		index;
	long	smallest;
	long	current;

	i = 0;
	index = 0;
	smallest = LONG_MAX;
	while (i < data->b_size)
	{
		current = ps_count_steps_two(data->b_size, i);
		current += (data->b_size - data->pool[i]) + abs(data->pool[i] - data->pool[data->b_size]);
		if (smallest > current)
		{
			smallest = current;
			index = i;
		}
		++i;
	}
	return (index);
}

void	ps_insert_to_a(t_data *data, int *pool)
{
	const int a = data->b_size;
	const int b = data->b_size - 1;
	const int a_size = data->pool_size - data->b_size;
	const int a_last = data->pool_size -1;

	if (pool[b] > pool[a] && pool[b] < pool[a + 1])
	{
		ps_exec(data, PA);
		ps_exec(data, SA);
		return;
	}
	while (pool[a] < pool[b])
		ps_exec(data, RA);
	while (!ps_is_sorted(&pool[a], a_size) && pool[a_last] > pool[b])
		ps_exec(data, RRA);
	ps_exec(data, PA);
}

void	ps_phase_two(t_data *data, int *pool, int *b_size, const int pool_size)
{
	int			smallest;
	int			a_size;

	while (*b_size > 0)
	{
		smallest = ps_find_smallest2(data);
		a_size = pool_size - *b_size;
		if (smallest == *b_size - 1)
			ps_insert_to_a(data, pool);
		else if (smallest > *b_size / 2)
		{
			if (pool[*b_size] < pool[smallest])
				ps_exec(data, RR);
			else
				ps_exec(data, RB);
		}
		else
		{
			if (!ps_is_sorted(pool + *b_size, a_size)
					&& pool[pool_size - 1] > pool[smallest])
				ps_exec(data, RRR);
			else
				ps_exec(data, RRB);
		}
	}
}
