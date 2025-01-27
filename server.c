/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:48:05 by jcoquet           #+#    #+#             */
/*   Updated: 2024/04/09 08:41:34 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "./libft/libft.h"

void	stocking_chars(unsigned char c, siginfo_t *info, int i)
{
	static unsigned char	*str = NULL;
	unsigned char			*tmp;

	if (!str)
		str = ft_strdup((unsigned char *)"");
	tmp = str;
	str = ft_strjoin(tmp, c);
	free (tmp);
	if (c == 0 || c == 255)
	{
		if (c == 0)
		{
			ft_printf("%s \n\nMessage from %i DONE\n\n", str, info->si_pid);
			kill(info->si_pid, SIGUSR1);
		}
		if (c == 255)
		{
			ft_printf("\n\nMessage from %i CANCELED\n\n", info->si_pid);
			kill(info->si_pid, SIGUSR2);
		}
		free (str);
		str = NULL;
		c = 0;
		i = 0;
	}
}

void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	character;
	static int				i;

	(void)ucontext;
	if (signal == 2)
	{
		ft_printf("\nserver %i is closing\n", getpid());
		exit (0);
	}
	if (i <= 7)
	{
		if (signal == SIGUSR1)
			character ^= 1 << i;
		else if (signal == SIGUSR2)
			character ^= 0 << i;
		if (i == 7)
		{
			stocking_chars(character, info, i);
			character = 0;
			i = 0;
		}
		else
			i++;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = 0;
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = &signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
	sigaction(SIGUSR2, &sa, NULL) == -1 || sigaction(SIGINT, &sa, NULL) == -1)
		return (1);
	ft_printf("server PID is : %d\n\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
