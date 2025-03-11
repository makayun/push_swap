/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:26:35 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/09 01:36:15 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_ra(t_data *data)
{
	int i;

	i = data->b_size;
	while (++i < data->pool_size)
		ps_switch(&data->pool[i], &data->pool[i - 1]);
	printf("ra\n");
}

void ps_rb(t_data *data)
{
	int i;

	i = data->b_size;
	while (--i > 0)
		ps_switch(&data->pool[i], &data->pool[i - 1]);
	printf("rb\n");
}

void ps_rr(t_data *data)
{
	int i;

	i = data->b_size;
	while (++i < data->pool_size)
		ps_switch(&data->pool[i], &data->pool[i - 1]);
	i = data->b_size;
	while (--i > 0)
		ps_switch(&data->pool[i], &data->pool[i - 1]);
	printf("rr\n");
}
