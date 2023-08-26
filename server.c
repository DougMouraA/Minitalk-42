/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:49:36 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/09/27 13:29:05 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

void	bit_sig(int sig, siginfo_t *info, void *oact)
{
	static int	i;
	static int	s;

	(void)(oact);
	if (sig == SIGUSR1)
		s += 1 << i;
	i++;
	if (i == 8)
	{
		if (s != 0)
			write (1, &s, 1);
		else
			kill (info-> si_pid, SIGUSR1);
		s = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = bit_sig;
	act.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &act, NULL);
	sigaction (SIGUSR2, &act, NULL);
	ft_putnbr_fd (getpid(), 1);
	while (1)
		pause ();
}
