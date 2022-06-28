/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 04:58:17 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/24 05:06:02 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_handler(int sigusr)
{
	static int	i;
	static int	shift;

	if (sigusr == SIGUSR1)
		shift += 1 << i;
	i++;
	if (i == 8)
	{
		write (1, &shift, 1);
		i = 0;
		shift = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr (pid);
	ft_putstr ("\n");
	signal (SIGUSR1, ft_handler);
	signal (SIGUSR2, ft_handler);
	while (1)
		pause ();
	return (0);
}
