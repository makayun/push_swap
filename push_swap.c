/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:43:22 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 20:28:33 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exit(t_data *data, const char *msg, const int code)
{
	free(data->pool);
	if (msg && *msg)
		perror(msg);
	exit(code);
}

void ps_finish_him(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->pool_size)
		if (data->pool[i] == 1)
			break;
	if (i <= data->pool_size / 2)
	{
		while (data->pool[0] != 1)
			ps_exec(data, RA);
	}
	else
		while (data->pool[0] != 1)
			ps_exec(data, RRA);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.pool = NULL;
	if (argc <= 1)
		ps_exit(&data, "Not enough arguments!", 42);
	data.pool_size = argc - 1;
	ps_init(&data, argv + 1);
	ps_phase_one(&data, data.pool, &data.b_size, data.pool_size);
	ps_phase_two(&data, data.pool, &data.b_size, data.pool_size);
	if (!ps_is_sorted(data.pool, data.pool_size))
		ps_finish_him(&data);
	ps_exit(&data, NULL, 0);
}
