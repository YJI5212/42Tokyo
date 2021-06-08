#include "atoi_test.h"

int	atoi_05_negative_test(void)
{
	if (atoi("    -21400") == ft_atoi("    -21400"))
		return (0);
	else
		return (-1);
}
