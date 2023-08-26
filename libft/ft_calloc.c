/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:38:51 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/06/15 14:38:51 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nitem, size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (nitem * size == 0)
	{
		mem = (char *)malloc(1);
		return (mem);
	}
	if (nitem == SIZE_MAX || size == SIZE_MAX)
		return (0);
	mem = malloc(nitem * size);
	if (!mem)
		return (0);
	ft_bzero (mem, nitem * size);
	return (mem);
}
