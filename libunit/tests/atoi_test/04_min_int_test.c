#include "atoi_test.h"

int	atoi_04_min_int_test(void)
{
	if (atoi("-2147483648") == ft_atoi("-2147483648"))
		return (0);
	else
		return (-1);
}
