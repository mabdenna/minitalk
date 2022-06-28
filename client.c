/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 05:10:23 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/24 05:18:04 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

void	bit_shift(int pid, char c)
{
	int	i;
	int	shift;

	i = 0;
	while (i < 8)
	{
		shift = (c & (1 << i));
		if (shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	d;

	d = 0;
	if (argc != 3)
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][d])
	{
		bit_shift(pid, argv[2][d]);
		d++;
	}
	return (0);
}
