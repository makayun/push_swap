/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:43:22 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 17:51:41 by mmakagon         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1)
		ps_exit(&data, "Not enough arguments!", 42);
	data.pool_size = argc - 1;
	ps_init(&data, argv + 1);
	ps_phase_one(&data, data.pool, &data.b_size, data.pool_size);
	ps_phase_two(&data, data.pool, &data.b_size, data.pool_size);
	return (0);
}
