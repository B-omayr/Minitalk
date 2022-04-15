/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:01:30 by iomayr            #+#    #+#             */
/*   Updated: 2022/02/07 15:49:48 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_minitalk	g_list;

void	set_to_zero(void)
{
	g_list.i = 0;
	g_list.c = 0;
	g_list.client_pid = 0;
}

void	ft_receive_b(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (g_list.client_pid != info->si_pid)
		set_to_zero();
	g_list.c += ((sig & 1) << g_list.i);
	g_list.i++;
	if (g_list.i == 8)
	{
		ft_printf("%c", g_list.c);
		if (!g_list.c)
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		set_to_zero();
	}
	g_list.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("your bonus server pid is :%d\n", getpid());
	action.sa_sigaction = ft_receive_b;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		sleep(1);
}
