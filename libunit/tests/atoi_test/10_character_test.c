#include "atoi_test.h"

int	atoi_10_character_test(void)
{
	if (atoi("      abcdefg  ") == ft_atoi("      abcdefg  "))
		return (0);
	else
		return (-1);
}
