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

void	receive_bit2(t_server *info)
{
	*(info->c) = 0;
	if (info->client_pid)
	{
		ft_putstr_fd("[ CLIENT PID : ", 1);
		ft_putnbr_fd(info->client_pid, 1);
		ft_putstr_fd(" ]", 1);
		ft_putendl_fd(info->str, 1);
		send_ack(info, g_signal);
		info->client_pid = 0;
	}
	else
	{
		info->client_pid = ft_atoi(info->str);
		send_ack(info, g_signal);
	}
	free(info->str);
	info->str = (char *)ft_calloc(1, sizeof(char));
}

void	recieve_bit(t_server *info)
{
	char	*tmp;

	if (g_signal == SIGUSR1)
		*(info->c) += ft_pow(2, info->bit_count);
	if (info->bit_count < 31)
		info->bit_count++;
	else
	{
		info->bit_count = 0;
		if (*(info->c) == 0x4)
		{
			receive_bit2(info);
			return ;
		}
		if (!*(info->str))
			ft_strlcpy(info->str, info->c, ft_strlen(info->c) + 1);
		else
		{
			tmp = info->str;
			info->str = ft_strjoin((const char *)(info->str),
					(const char *)(info->c));
			free(tmp);
		}
		*(info->c) = 0;
	}
}
