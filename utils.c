/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:28:41 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/02/17 13:44:52 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		num = (unsigned int)(n * (-1));
		write(fd, "-", 1);
	}
	else
		num = (unsigned int)n;
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
	{
		num = (num + '0');
		write(fd, &num, 1);
	}
}

int	ft_atoi(const char *s)
{
	int		i;
	int		ng;
	long	res;

	i = 0;
	ng = 1;
	res = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			ng = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		if ((res * ng < -2147483648) || (res * ng > 2147483648))
			return ((res * ng < -2147483648) - 1);
		i++;
	}
	return (res * ng);
}
