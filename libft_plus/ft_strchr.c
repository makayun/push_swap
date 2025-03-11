/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:03:36 by mmakagon          #+#    #+#             */
/*   Updated: 2025/03/11 20:17:34 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr( char *s, int c)
{
	unsigned char	ch;

	ch = (char)c;
	while (*s != ch && *s != '\0')
		s++;
	if (*s == ch)
		return ((char *)s);
	else
		return (0);
}
