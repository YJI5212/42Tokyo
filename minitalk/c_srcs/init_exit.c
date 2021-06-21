#include "../includes/client.h"

void	init_client(t_client *info, char *argv[])
{
	info->client_pid = getpid();
	info->server_pid = ft_atoi(argv[1]);
	info->message = ft_itoa(info->client_pid);
	if (signal(SIGUSR1, signal_handler) == SIG_ERR
		|| signal(SIGUSR2, signal_handler) == SIG_ERR)
		exit_client(false);
}

void	exit_client(bool torf)
{
	if (torf == true)
	{
		ft_putendl_fd("== Client is successfully exited. ==", 1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putendl_fd("== Client is unexpectedlly exited. ==", 1);
		exit(EXIT_FAILURE);
	}
}
