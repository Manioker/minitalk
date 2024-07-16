/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:39:20 by andi              #+#    #+#             */
/*   Updated: 2024/07/16 22:14:17 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_recursive_power(int nb, int power)
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

char	*letter_to_string(char *string, char const letter)
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
	free (string);
	return (tab);
}

void	signal_handler(int signum)
{
	static int	result = 0;
	static int count = 0;
	static char	*string;

	if (!string)
	{
		string = malloc(1 * sizeof(char));
		string[0] = '\0';
	}
	if (signum == SIGUSR1)
		result = result + 0;
	else if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - counter));
	count++;
	if (count == 8)
	{
		string = addletter(string, result);
		if (result == '\0')
		{
			ft_printf("%s", string)
			string = NULL;
		}
		count = 0;
		result = 0
	}

}

int main(void)
{
	ft_printf("Server's PID: %d\n", getpid());
	signal(SIGUSR1, signal_read);
	signal(SIGUSR2, signal_read);
	while (1)
		usleep(100);
}