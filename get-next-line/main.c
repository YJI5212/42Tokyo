#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int rc;
	char *line;

	(void)argc;
	while (*(++argv))
	{
		fd = open(*argv, O_RDONLY);
		//fd = 2;
		while ((rc = get_next_line(fd, &line)) != -1)
		{
			if (rc == 1)
			{
				printf("READ:%s\n", line);
				free(line);
				line = NULL;
			}
			else
			{
				printf("EOF:%s\n", line);
				free(line);
				break ;
			}
		}
		printf("rc=%d\n",rc);
	}
	return (0);
}
