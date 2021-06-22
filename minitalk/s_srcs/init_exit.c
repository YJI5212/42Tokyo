#include "../includes/server.h"

void	init_server(t_server *info)
{
	char	*server_pid;

	server_pid = ft_itoa(getpid());
	ft_putstr_fd(" SERVER PID : ", 1);
	ft_putendl_fd(server_pid, 1);
	free(server_pid);
	g_signal = 0;
	if (signal(SIGUSR1, signal_handler) == SIG_ERR
		|| signal(SIGUSR2, signal_handler) == SIG_ERR
		|| signal(SIGINT, signal_handler) == SIG_ERR
		|| signal(SIGQUIT, signal_handler) == SIG_ERR)
		exit_server(false);
	info->bit_count = 0;
	info->str = (char *)ft_calloc(1, sizeof(char));
	info->c = (char *)ft_calloc(1, sizeof(char));
	if (!info->str || !info->c)
		exit_server(false);
}

void	exit_server(bool torf)
{
	if (torf == true)
		ft_putendl_fd("== Server is successfully exited. ==", 1);
	else
		ft_putendl_fd("== Server is unexpectedlly exited. ==", 1);
	exit(EXIT_SUCCESS);
}
