/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:48:51 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 20:17:34 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	l = 0;
	new_str = (char *) malloc(i + j + 1);
	if (!new_str)
		return (NULL);
	while (s1[k] != '\0')
	{
		new_str[k] = s1[k];
		k++;
	}
	while (s2[l] != '\0')
	{
		new_str[k + l] = s2[l];
		l++;
	}
	new_str[k + l] = '\0';
	return ((char *)new_str);
}
