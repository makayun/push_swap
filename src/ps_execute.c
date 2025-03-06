#include "push_swap.h"

void	ps_execute_s(const char *command, t_data *data)
{
	if (command[1] == 'a' || command[1] == 's')
		ps_swap(data->a);
	if (command[1] == 'b' || command[1] == 's')
		ps_swap(data->b);
}

void	ps_execute_p(const char *command, t_data *data)
{
	if (command[1] == 'a')
	{
		data->last_a++;
		ps_push(data->b, data->a, data->last_b, data->last_a);
		data->last_b--;
	}
	else if (command[1] == 'b')
	{
		data->last_b++;
		ps_push(data->a, data->b, data->last_a, data->last_b);
		data->last_a--;
	}
}

void	ps_execute_r(const char *command, t_data *data)
{
	if (command[1] == 'a' || command[1] == 'r')
		ps_rotate(data->a, data->last_a);
	if (command[1] == 'b' || command[1] == 'r')
		ps_rotate(data->b, data->last_b);
}

void	ps_execute_rr(const char *command, t_data *data)
{
	if (command[2] == 'a' || command[2] == 'r')
		ps_reverse_rotate(data->a, data->last_a);
	if (command[2] == 'b' || command[2] == 'r')
		ps_reverse_rotate(data->b, data->last_b);
}

void	ps_execute(const char *command, t_data *data)
{
	if (command[0] == 's')
		ps_execute_s(command, data);
	else if (command[0] == 'p')
		ps_execute_p(command, data);
	else if (command[0] == 'r' && command[2] == '\0')
		ps_execute_r(command, data);
	else if (command[2] != '\0' && command[1] == 'r' && command[0] == 'r')
		ps_execute_rr(command, data);
	ft_printf ("%s\n", command);
}
