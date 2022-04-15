/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:08:48 by iomayr            #+#    #+#             */
/*   Updated: 2022/02/07 15:49:14 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include "ft_printf/libftprintf.h"

typedef struct s_minitalk{
	int		i;
	char	c;
	int		client_pid;
}t_minitalk;

void	ft_send(int pid, char *str, int len);
void	ft_receice_b(int sig, siginfo_t *info, void *ucontext);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	handler2(int sig);

#endif
