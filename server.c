/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:39:20 by andi              #+#    #+#             */
/*   Updated: 2024/09/18 12:13:17 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_recursive_power(nb, power - 1);
		return (res);
	}
}

static char	*addletter(char *string, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((ft_strlen(string) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (string[i])
		tab[j++] = string[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free(string);
	return (tab);
}

static void	signal_handler(int signum)
{
	static int	result = 0;
	static int	count = 0;
	static char	*string;

	if (!string)
	{
		string = malloc(1 * sizeof(char));
		string[0] = '\0';
	}
	if (signum == SIGUSR1)
		result = result + 0;
	else if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - count));
	count++;
	if (count == 8)
	{
		string = addletter(string, result);
		if (result == '\0')
		{
			ft_putstr(string);
			string = NULL;
		}
		count = 0;
		result = 0;
	}
}

int	main(void)
{
	ft_putstr("server's PID : ");
	ft_putnbr(getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		usleep(2000);
}
