/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:48:53 by jcoquet           #+#    #+#             */
/*   Updated: 2024/04/09 08:42:45 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "./libft/libft.h"

int	g_pid;

static void	handle_sigint(int sig)
{
	int	i;

	if (sig == SIGINT)
	{
		i = 0;
		while (i++ <= 16)
		{
			kill(g_pid, SIGUSR1);
			usleep(500);
		}
		exit (0);
	}
}

static void	handle_sigusr2(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("\n\nTransmission CANCELED\n\n");
		exit (0);
	}
}

static void	handle_sigusr1(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("\nMessage received by the server\n\n");
		exit (0);
	}
}

static void	ft_send_msg(char *str, int pid)
{
	int				i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if ((unsigned char)*str & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
			i++;
		}
		str++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(1000);
	}
	while (1)
		usleep(10);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc == 3)
	{
		signal(SIGUSR1, handle_sigusr1);
		signal(SIGUSR2, handle_sigusr2);
		signal(SIGINT, handle_sigint);
		pid = ft_atoi(argv[1]);
		g_pid = pid;
		str = argv[2];
		if (str[0] == 0)
			ft_printf("No message to send!");
		else
			ft_send_msg(argv[2], pid);
	}
	else
		ft_printf("Enter arguments as follow: ./client <PID> <MESSAGE>");
	return (0);
}
