/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:23:18 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 20:17:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline	void	ps_switch(int *restrict a, int *restrict b)
{
	const int	temp = *a;

	*a = *b;
	*b = temp;
}

bool	ps_is_sorted(const int *arr, const int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (arr[i] < arr[i - 1])
			return (false);
	}
	return (true);
}
