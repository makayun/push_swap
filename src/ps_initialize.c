#include "push_swap.h"

int	ps_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == '-' || str[i] == '+')
			i++;
		if (!(ft_isdigit(str[i++])))
			return (0);
	}
	return (1);
}

void	ps_number_array(t_data *data)
{
	int	i;
	int	j;
	int	count;
	int	repeat;

	i = 0;
	while (i < data->size)
	{
		j = 0;
		repeat = 0;
		count = 1;
		while (j < data->size)
		{
			if (data->b[j] < data->b[i])
				count++;
			else if (data->b[j] == data->b[i] && ++repeat > 1)
					ps_exit(data, "Error, equal numbers\n", 1);
			j++;
		}
		data->a[i] = count;
		i++;
	}
}

void	ps_fill_w_zeros(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
		stack[i++] = 0;
}

void	ps_initialize(char **argv, t_data *data)
{
	int		i;
	long	temp;

	i = 1;
	while (argv[i])
	{
		if (!(ps_is_number(argv[i])))
			ps_exit(data, "Error, some argument is not a number", 1);
		temp = ft_atoi(argv[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			ps_exit(data, "Error, an argument is outside the range of int", 1);
		data->b[i - 1] = temp;
		i++;
	}
	if (data->size == 2 && data->b[0] > data->b[1])
		ps_exit(data, "sa\n", 0);
	ps_number_array(data);
	if (ps_check_if_sorted(data->a, data->size))
		ps_exit(data, "", 0);
	ps_fill_w_zeros(data->b, data->size);
	data->last_a = data->size - 1;
	data->last_b = -1;
	data->mid = (data->size >= 100) * (data->size / 100);
}
