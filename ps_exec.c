/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:47:31 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 19:25:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_init(void (*f[COMMANDS_MAX])(t_data *data))
{
	f[PA] = ps_pa;
	f[PB] = ps_pb;
	f[SA] = ps_sa;
	f[SB] = ps_sb;
	f[SS] = ps_ss;
	f[RA] = ps_ra;
	f[RB] = ps_rb;
	f[RR] = ps_rr;
	f[RRA] = ps_rra;
	f[RRB] = ps_rrb;
	f[RRR] = ps_rrr;
}

void	ps_exec(t_data *data, unsigned char code)
{
	static void	(*f[COMMANDS_MAX])(t_data *data) = {NULL};
	static char	to_print[COMMANDS_MAX][4] = {"pa", "pb", "sa", "sb", "ss",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	if (!f[0])
		f_init(f);
	if (code < COMMANDS_MAX && f[code])
	{
		f[code](data);
		printf("%s\n", to_print[code]);
	}
}
