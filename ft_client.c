/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:20 by iomayr            #+#    #+#             */
/*   Updated: 2022/02/07 16:10:16 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			if (!((str[i] >> shift) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift++;
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("The Number of argument incorrect");
		return (0);
	}
	pid = ft_atoi(av[1]);
	ft_send(pid, av[2], ft_strlen(av[2]));
}
