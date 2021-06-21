#include "../includes/client.h"

void	signal_handler(int signal)
{
	g_signal = signal;
}

int	wait_ack(void)
{
	while (1)
	{
		pause();
		return (EXIT_SUCCESS);
	}
}

void	send_signal(pid_t server_pid, int bit)
{
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else if (bit == 0)
		kill(server_pid, SIGUSR2);
}

void	send_bit(pid_t server_pid, char c)
{
	int		i;
	int32_t	bits;

	i = -1;
	bits = (int32_t)c;
	while (++i < 32)
	{
		if (bits & 0x1)
			send_signal(server_pid, 1);
		else
			send_signal(server_pid, 0);
		bits = bits >> 1;
		usleep(485);
	}
}

void	send_message(t_client *info)
{
	while (*(info->message))
	{
		send_bit(info->server_pid, *(info->message));
		info->message++;
	}
	send_bit(info->server_pid, EOT);
	wait_ack();
}
