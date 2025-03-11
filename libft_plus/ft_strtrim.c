/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:59:57 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 20:17:34 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char  *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char  *s1, char  *set)
{
	char	*trimmed;
	int		i;
	int		n;
	int		l;

	i = 0;
	l = 0;
	while (ft_is_in_set(s1[i], set))
		i++;
	n = ft_strlen (s1);
	while (ft_is_in_set(s1[n - 1], set) && n != i)
		n--;
	trimmed = (char *) malloc(n - i + 1);
	if (!trimmed)
		return (NULL);
	while (i < n)
	{
		trimmed[l] = s1[i];
		i++;
		++l;
	}
	trimmed[l] = '\0';
	return ((char *)trimmed);
}
