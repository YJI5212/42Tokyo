#include "atoi_test.h"

int	atoi_03_max_int_test(void)
{
	if (atoi("2147483647") == ft_atoi("2147483647"))
		return (0);
	else
		return (-1);
}
