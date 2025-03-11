/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:53:33 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 14:52:16 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_data *data)
{
	--data->b_size;
}

void	ps_pb(t_data *data)
{
	++data->b_size;
}

void	ps_sa(t_data *data)
{
	ps_switch(&data->pool[data->b_size], &data->pool[data->b_size + 1]);
}

void	ps_sb(t_data *data)
{
	ps_switch(&data->pool[data->b_size - 1], &data->pool[data->b_size - 2]);
}

void	ps_ss(t_data *data)
{
	ps_sa(data);
	ps_sb(data);
}
