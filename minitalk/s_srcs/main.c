#include "../includes/server.h"

void	check_args(int argc)
{
	if (argc != 1)
		exit_server(false);
}

int	main(int argc, char *argv[])
{
	t_server	info;

	(void)argv;
	check_args(argc);
	init_server(&info);
	while (1)
	{
		pause();
		if (g_signal == SIGUSR1 || g_signal == SIGUSR2)
			recieve_bit(&info);
		if (g_signal == SIGINT || g_signal == SIGQUIT)
		{
			free(info.str);
			free(info.c);
			exit_server(true);
		}
	}
	return (EXIT_SUCCESS);
}
