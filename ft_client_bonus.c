/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:24:05 by iomayr            #+#    #+#             */
/*   Updated: 2022/02/07 16:10:02 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_send(int pid, char *str, int len)
{
	int	shift;
	int	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 8)
		{
			if (((str[i] >> shift) & 1))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(500);
		}
		i++;
	}
}

void	handler2(int sig)
{
	(void)sig;
	ft_printf("Everything is okeey \n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	action;

	action.sa_handler = handler2;
	sigaction(SIGUSR2, &action, NULL);
	if (ac != 3)
	{
		ft_printf("The Number of argument incorrect");
		return (0);
	}
	pid = ft_atoi(av[1]);
	ft_send(pid, av[2], ft_strlen(av[2]));
}
