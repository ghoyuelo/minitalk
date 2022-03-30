/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:12:09 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/02/17 14:13:30 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sig)
{
	static int	exp;
	static int	c;
	static int	bit;

	if (!c || bit == 8)
		c = 0;
	if (!bit || bit == 8)
		bit = 0;
	if (!exp || bit == 0)
		exp = 1;
	if (sig == SIGUSR2)
		c = c + exp;
	bit++;
	exp = exp * 2;
	if (bit == 8)
		write(1, &c, 1);
	if (bit == 8 && !c)
		write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		write(1, "\x1B[31mError. Put: ./server\n\x1B[31m", 33);
		exit (0);
	}
	pid = getpid();
	write(1, "\x1B[32mServer PID: \x1B[32m", 23);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
