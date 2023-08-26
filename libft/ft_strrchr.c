/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglasmoura <douglasmoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:16:58 by douglasmour       #+#    #+#             */
/*   Updated: 2022/06/19 14:16:58 by douglasmour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	c = c % 256;
	size = ft_strlen(s);
	while (size >= 0)
	{
		if (s[size] == c)
			return ((char *)&s[size]);
		size--;
	}
	if (c == 0)
		return ((char *) s);
	return (NULL);
}
