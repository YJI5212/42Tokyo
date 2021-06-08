#include "atoi_test.h"

int	atoi_08_double_plus_test(void)
{
	if (atoi("      ++100  ") == ft_atoi("      ++100  "))
		return (0);
	else
		return (-1);
}
