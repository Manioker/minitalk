/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:49:23 by andi              #+#    #+#             */
/*   Updated: 2024/09/18 12:07:36 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b = -b;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		a = (a * 10) + (str[i] - '0');
		i++;
	}
	return (a * b);
}

static void	send_message(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			if (((unsigned char)(message[i] >> (7 - j)) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			j++;
		}
		i++;
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*message;

	if (ac != 3)
	{
		ft_putstr("not enough/too much arguments\n");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	if (!server_pid)
	{
		ft_putstr("ERROR: wrong PID\n");
		return (0);
	}
	message = av[2];
	if (message[0] == '\0')
	{
		ft_putstr("pls write a message\n");
		return (0);
	}
	send_message(server_pid, message);
	return (0);
}
