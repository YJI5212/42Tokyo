#include "atoi_test.h"

int	atoi_09_double_minus_test(void)
{
	if (atoi("      --100  ") == ft_atoi("      --100  "))
		return (0);
	else
		return (-1);
}
