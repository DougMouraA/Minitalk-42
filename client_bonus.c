/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:49:26 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/09/27 14:28:56 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

void	recived_sig(int sig)
{
	if (sig == SIGUSR1)
		write (1, "ok", 2);
}

void	dec_to_bnr(int num, pid_t pid)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (num & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep (300);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	i = 0;
	signal (SIGUSR1, recived_sig);
	if (argc == 3)
	{
		pid = ft_atoi (argv[1]);
		while (argv[2][i] != '\0')
		{
			dec_to_bnr (argv[2][i], pid);
			i++;
		}
		dec_to_bnr (argv[2][i], pid);
	}
	else if (argc != 3)
		write (1, "ERROR", 5);
	return (0);
}
