#include "atoi_test.h"

int	atoi_07_non_numeric_test(void)
{
	if (atoi("        ") == ft_atoi("        "))
		return (0);
	else
		return (-1);
}
