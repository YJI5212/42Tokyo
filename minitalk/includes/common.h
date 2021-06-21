#ifndef COMMON_H
# define COMMON_H

# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <inttypes.h>
# include "../libft/libft.h"

int	g_signal;

void	signal_handler(int signal);

#endif
