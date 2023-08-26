/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:40 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/06/15 14:50:40 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	lennum(int n)
{
	int	i;

	i = 1;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		sizeint;
	char	*strint;
	int		negsing;

	sizeint = (lennum(n) - 1);
	strint = (char *)malloc(sizeint + 1);
	if (!strint)
		return (0);
	negsing = 1;
	strint[sizeint--] = '\0';
	strint[0] = '0';
	if (n < 0)
	{
		strint[0] = '-';
		negsing = -1;
	}
	while (n != 0)
	{
		strint[sizeint] = (negsing * (n % 10)) + '0';
		n = n / 10;
		sizeint--;
	}
	return (strint);
}
