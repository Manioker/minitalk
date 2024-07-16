/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:49:23 by andi              #+#    #+#             */
/*   Updated: 2024/07/16 22:15:55 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *message)
{
	int	i;
	int	j;

	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			if (((unsigned char)(message[i] >> (7 - j)) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*message;

	if (ac != 3)
	{
		ft_printf("not enough/too much arguments\n");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	if (!server_pid)
	{
		ft_printf("ERROR: wrong PID\n");
		return (0);
	}
	message = av[2];
	if (message[0] == '\0')
	{
		ft_printf("pls write a message\n");
		return (0);
	}
	send_message(server_pid, message);
	return (0);
}
