/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:50:40 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/06/15 15:50:40 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *str, int fd)
{
	int		count;
	char	i;

	i = '\n';
	count = 0;
	if (!str)
		return ;
	while (*(str + count) != '\0')
	{
		write (fd, &*(str + count), 1);
		count++;
	}
	write (fd, &i, 1);
}
