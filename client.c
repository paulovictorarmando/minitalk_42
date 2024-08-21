/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:37:07 by parmando          #+#    #+#             */
/*   Updated: 2024/08/11 16:46:45 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_accepted = 0;

void	confirmation(int sig)
{	
	if (sig == SIGUSR1)
		g_accepted = 1;
	else
		g_accepted = 0;
}

void	ft_encrypt_and_send(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_accepted == 0)
			pause();
		g_accepted = 0;
		i--;
	}
	write(1, "Caracter ", 9);
	write(1, &c, 1);
	write(1, " enviado com sucesso\n", 22);
}

int	ft_atoi(char *s)
{
	int	sinal;
	int	res;

	res = 0;
	sinal = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sinal = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sinal);
}

int	main(int argc, char *argv[])
{
	char	*message;
	int		pid;

	signal(SIGUSR1, confirmation);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		while (*message)
		{
			ft_encrypt_and_send(pid, *message);
			message++;
		}
	}
	return (0);
}
