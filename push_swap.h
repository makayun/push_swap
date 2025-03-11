/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:37:20 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/09 08:01:35 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

enum e_command {
	EPA,
	EPB,
	ESA,
	ESB,
	ESS,
	ERA,
	ERB,
	ERR,
	ERRA,
	ERRB,
	ERRR,
	COMMANDS_MAX
};

enum e_operation {
	PA	= 0x01,
	PB	= 0x02,
	RA	= 0x04,
	RB	= 0x08,
	RRA	= 0x10,
	RRB	= 0x20,
	SA	= 0x40,
	SB	= 0x80,
	RR	= RA | RB,
	RRR	= RRA | RRB,
	SS	= SA | SB
};

typedef struct	s_data {
	int			*pool;
	const int	pool_size;
	int			b_size;
}				t_data;

void	ps_init(t_data *data, char **numbers);
void	ps_exit(t_data *data, const char *msg, const int code);

void	ps_pa(t_data *data);
void	ps_pb(t_data *data);
void	ps_sa(t_data *data);
void	ps_sb(t_data *data);
void	ps_ss(t_data *data);
void	ps_ra(t_data *data);
void	ps_rb(t_data *data);
void	ps_rr(t_data *data);
void	ps_rra(t_data *data);
void	ps_rrb(t_data *data);
void	ps_rrr(t_data *data);
void	ps_exec(t_data *data, unsigned char code);

void	ps_switch(int *a, int *b);
bool	ps_is_sorted(const int *arr, const int size);

void	ps_phase_one(t_data *data);

#endif
