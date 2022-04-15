/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:11:14 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/17 17:39:06 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "ft_printf/libftprintf.h"

typedef struct s_minitalk
{
	char	c;
	int		i;
	int		client_pid;
}t_minitalk;

void	ft_send(int pid, char *str, int len);
int		ft_strlen(const char *str);
unsigned int		ft_atoi(const char *str);
void	ft_receive(int sig, siginfo_t *info, void *ucontext);

#endif
