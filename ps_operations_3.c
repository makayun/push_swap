/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:38:44 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 14:53:24 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_data *data)
{
	int	i;

	i = data->pool_size;
	while (--i > data->b_size)
		ps_switch(&data->pool[i], &data->pool[i - 1]);
}

void	ps_rrb(t_data *data)
{
	int	i;

	i = 0;
	while (++i < data->b_size)
		ps_switch(&data->pool[i], &data->pool[i - 1]);
}

void	ps_rrr(t_data *data)
{
	ps_rra(data);
	ps_rrb(data);
}
