#include "../includes/client.h"

void	check_args(int argc, char *argv[])
{
	(void)argv;
	if (argc != 3)
		exit_client(false);
}

int	main(int argc, char *argv[])
{
	t_client	info;
	char		*head;

	check_args(argc, argv);
	init_client(&info, argv);
	head = info.message;
	send_message(&info);
	free(head);
	info.message = argv[2];
	send_message(&info);
	return (EXIT_SUCCESS);
}
