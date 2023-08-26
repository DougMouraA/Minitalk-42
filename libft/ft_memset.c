/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:44:09 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/06/15 15:44:09 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	d;
	size_t	i;
	char	*str;

	str = (char *)s;
	d = c;
	i = 0;
	while (i < n)
	{
		str[i] = d;
		i++;
	}
	return (str);
}
