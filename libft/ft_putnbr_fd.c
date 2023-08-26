/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglasmoura <douglasmoura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:53:42 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/06/18 10:51:32 by douglasmour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>

static void	negativ_n(int fd)
{
	char	neg;

	neg = '-';
	write (fd, &neg, 1);
}

static size_t	verify_n(int n)
{
	size_t	ncpy;

	if (n < 0)
	{
		if (n == -2147483648)
			ncpy = 2147483648;
		else
			ncpy = (-1 * n);
	}
	else
		ncpy = n;
	return (ncpy);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	size;
	size_t	ncpy;
	char	strnum;

	ncpy = verify_n(n);
	size = 1;
	if (n < 0)
		negativ_n(fd);
	while (ncpy >= 10)
	{
		ncpy = ncpy / 10;
		size = size * 10;
	}
	ncpy = verify_n(n);
	while (size > 0)
	{
		strnum = (ncpy / size) + '0';
		write(fd, &strnum, 1);
		ncpy = ncpy % size;
		size = size / 10;
	}
}
