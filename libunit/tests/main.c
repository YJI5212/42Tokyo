#include "tests.h"

int	main(void)
{
	int	ret;

	ret = 0;
	setvbuf(stdout, (char *) NULL, _IONBF, 0);
	printf("*****************************************\n");
	printf("****         42 - Unit Tests         ****\n");
	printf("*****************************************\n");
	ret |= strlen_launcher();
	ret |= atoi_launcher();
	return (ret);
}
