/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:12:25 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/02/17 14:17:53 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(120);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (argc == 3)
	{
		s = argv[2];
		pid = ft_atoi(argv[1]);
		while (s[i])
		{
			send_bit(s[i], pid);
			i++;
		}
		send_bit('\n', pid);
	}
	else
		write (1, "\x1B[31mPut: ./client [PID] String\n\x1B[31m", 39);
	return (0);
}
