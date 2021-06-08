#include "atoi_test.h"

int	atoi_01_basic_test(void)
{
	if (atoi("    \t\n\n\v  -12345f  ") == ft_atoi("    \t\n\n\v  -12345f  "))
		return (0);
	else
		return (-1);
}
