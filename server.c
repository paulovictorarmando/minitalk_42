/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:17:25 by parmando          #+#    #+#             */
/*   Updated: 2024/08/11 16:46:31 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decrypt_and_put(int sig, siginfo_t *info, void *context)
{
	static int					bit_count = 7;
	static pid_t				pid_client = 0;
	static unsigned char		current_char = 0;

	
	(void)context;
	pid_client = info->si_pid;
	if (sig == SIGUSR1)
		current_char |= (1 << (bit_count));
	bit_count--;
	if (bit_count < 0)
	{
		write(1, &current_char, 1);
		bit_count = 7;
		current_char = 0;
	}
	kill(pid_client, SIGUSR1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_sigaction = decrypt_and_put;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{	
		pause();
	}
	return (0);
}
