/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:32:08 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/02/17 13:45:39 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *s)
{
	static int	i;
	static int	bit;

	(void)info;
	(void)s;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		if (!i)
			write(1, "\n", 1);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sig_act;

	(void)argv;
	if (argc != 1)
	{
		write(1, "\x1B[31mError. Put: ./server_bonus\n\x1B[31m", 39);
		return (0);
	}
	pid = getpid();
	write(1, "\x1B[32mServer_Bonus PID: \x1B[32m", 29);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sig_act.sa_sigaction = sig_handler;
	sigemptyset(&sig_act.sa_mask);
	sig_act.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sig_act, NULL);
		sigaction(SIGUSR2, &sig_act, NULL);
		pause();
	}
	return (0);
}
