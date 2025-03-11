/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:37:20 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 18:53:07 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>

enum e_command
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	COMMANDS_MAX
};

typedef struct s_data
{
	int			*pool;
	int			pool_size;
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
int		ps_average(const int *arr, const int size);

void	ps_phase_one(t_data *data, int *pool, int *b_size, const int pool_size);
void	ps_phase_two(t_data *data, int *pool, int *b_size, const int pool_size);

#endif
