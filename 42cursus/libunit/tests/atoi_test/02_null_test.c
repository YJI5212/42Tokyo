#include "atoi_test.h"

int	atoi_02_null_test(void)
{
	if (atoi("") == ft_atoi(""))
		return (0);
	else
		return (-1);
}
