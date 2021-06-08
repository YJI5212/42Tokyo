#include "atoi_test.h"

int	atoi_11_space_insertion_test(void)
{
	if (atoi("      -       100  10104  ") == ft_atoi("      -       100  10104  "))
		return (0);
	else
		return (-1);
}
