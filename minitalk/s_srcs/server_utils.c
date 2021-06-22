#include "../includes/server.h"

void	signal_handler(int signal)
{
	g_signal = signal;
}

void	send_ack(t_server *info, int signal)
{
	usleep(700);
	kill(info->client_pid, signal);
}

int	ft_pow(int num, int pow)
{
	int	ret;

	ret = 1;
	while (pow-- > 0)
		ret *= num;
	return (ret);
}
