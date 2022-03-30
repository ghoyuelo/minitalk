/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:31:51 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/02/17 14:35:01 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_return(int signal)
{
	if (signal == SIGUSR1)
		write(1, "\033[0;31m❌\n\033[0;31m", 17);
	else
		write(1, "\033[0;32m✅\n\033[0;32m", 17);
}

int	send_bit(pid_t pid, char sig)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((sig & (1 << bit)) != 0)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep (100);
		bit++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	c;

	c = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1)
			return (0);
		while (argv[2][c])
		{
			signal(SIGUSR1, sig_return);
			signal(SIGUSR2, sig_return);
			send_bit(pid, argv[2][c]);
			c++;
		}
		send_bit(pid, '\n');
	}
	else
	{
		write (1, "\x1B[31mPut: ./client_bonus [PID] String\n\x1B[31m", 45);
		return (1);
	}
	return (0);
}
