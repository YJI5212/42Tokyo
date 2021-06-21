#ifndef SERVER_H
# define SERVER_H

# include "./common.h"

typedef struct s_server
{
	pid_t	client_pid;
	int		bit_count;
	char	*str;
	char	*c;
}	t_server;

void	init_server(t_server *info);
void	recieve_bit(t_server *info);
void	exit_server(bool torf);
void	signal_handler(int signal);

#endif
