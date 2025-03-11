/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:43:22 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/09 08:01:53 by mmakagon         ###   ########.fr       */
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
	t_data	data = {.pool_size = argc - 1};

	if (argc <= 1)
		ps_exit(&data, "Not enough arguments!", 42);
	ps_init(&data, argv + 1);
	ps_phase_one(&data);
}
