#ifndef CLIENT_H
# define CLIENT_H

# include "./common.h"

# define EOT 0x4

typedef struct s_client
{
	pid_t	client_pid;
	pid_t	server_pid;
	char	*message;
}	t_client;

void	init_client(t_client *info, char *argv[]);
void	exit_client(bool torf);
void	signal_handler(int signal);
void	send_message(t_client *info);
void	send_bit(pid_t server_pid, char c);
void	send_signal(pid_t server_pid, int bit);

#endif
