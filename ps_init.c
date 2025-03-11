/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:17:06 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 20:30:42 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_trim_spaces(const char *str, int i)
{
	if (str)
		while (str[i] && (str[i] == ' ' || str[i] == '	'))
			++i;
	return (i);
}

bool	ps_is_number(const char *str)
{
	const char	*numbers = "0123456789";
	int			i;

	if (!str || !*str)
		return (false);
	i = ps_trim_spaces(str, 0);
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		++i;
	while (str[i] && str[i] != ' ' && str[i] != '	')
	{
		if (!strchr(numbers, str[i]))
			return (false);
		++i;
	}
	i = ps_trim_spaces(str, i);
	if (str[i])
		return (false);
	return (true);
}

bool	ps_has_duplicates(const int *arr, const int size)
{
	int	i;
	int	j;

	if (!arr)
		return (false);
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (arr[j] == arr[i])
				return (true);
	}
	return (false);
}

void	ps_number_array(t_data *data)
{
	int	i;
	int	j;
	int	count;
	int	repeat;
	int *ranks;

	ranks = (int *)malloc(data->pool_size * sizeof(int));
	if (!ranks)
		ps_exit(data, "Not enough memory", 42);
	i = 0;
	while (i < data->pool_size)
	{
		j = 0;
		repeat = 0;
		count = 1;
		while (j < data->pool_size)
		{
			if (data->pool[j] < data->pool[i])
				count++;
			j++;
		}
		ranks[i] = count;
		i++;
	}
	i = -1;
	while (++i < data->pool_size)
		data->pool[i] = ranks[i];
	free(ranks);
}

void	ps_init(t_data *data, char **numbers)
{
	int		i;
	long	temp;

	data->pool = (int *)malloc(data->pool_size * sizeof(int));
	if (!data->pool)
		ps_exit(data, "Not enough memory!", 42);
	data->b_size = 0;
	i = 0;
	while (i < data->pool_size && numbers[i])
	{
		if (!ps_is_number(numbers[i]))
			ps_exit(data, "Not a number", 42);
		temp = atol(numbers[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			ps_exit(data, "The number is outside the bounds of an integer", 42);
		data->pool[i] = (int)temp;
		++i;
	}
	if (ps_has_duplicates(data->pool, data->pool_size))
		ps_exit(data, "There are duplicates in the array!", 42);
	ps_number_array(data);
}
