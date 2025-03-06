#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft_plus/libft.h"

enum e_commands {
	SA = 1,
	SB = 2,
	RA = 4,
	RB = 8,
	RRA = 16,
	RRB = 32
};

typedef struct s_data {
	int	*a;
	int	*b;
	int *weights;
	int	size;
	int	last_a;
	int	last_b;
	int	mid;
}				t_data;


void	ps_exit(t_data *data, char *message, int code);
void	ps_initialize(char **argv, t_data *data);
int		ps_is_number(char *str);
int		ps_check_if_sorted(int *stack, int size);
void	ps_number_array(t_data *data);
void	ps_fill_w_zeros(int *stack, int size);
void	ps_move_up(int *stack, int last);
void	ps_move_down(int *stack, int last);
void	ps_swap(int *stack);
void	ps_push(int *stack_from, int *stack_to, int last_from, int last_to);
void	ps_rotate(int *stack, int last);
void	ps_reverse_rotate(int *stack, int last);
void	ps_execute_s(const char *command, t_data *data);
void	ps_execute_p(const char *command, t_data *data);
void	ps_execute_r(const char *command, t_data *data);
void	ps_execute_rr(const char *command, t_data *data);
void	ps_execute(const char *command, t_data *data);
void	push_swap(t_data *data);
int		ps_check_for_phase_one(t_data *data);
void	ps_phase_one_pre_sorting(t_data *data);
int		ps_phase_one_find_the_smallest(t_data *data);
void	ps_phase_one_find_n_move(t_data *data);
void	ps_phase_one(t_data *data);
int		ps_check_for_phase_two(t_data *data);
void	ps_phase_two(t_data *data);
int sum(int *arr, int size);

#endif
