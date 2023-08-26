/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:00:23 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/06/15 15:00:23 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*cpy_strl(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = (char *)str1;
	src = (const char *)str2;
	if (n == 0 || (!dest && !src && n > 0))
		return (dest);
	if (dest < src)
	{
		cpy_strl(dest, src, n);
		return (dest);
	}
	i = n - 1;
	while (i != 0)
	{
		dest[i] = src[i];
		i--;
	}
	dest[i] = src[i];
	return (dest);
}
