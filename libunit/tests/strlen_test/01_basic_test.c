#include "strlen_test.h"

int	strlen_01_basic_test(void)
{
	if (strlen("abc") == ft_strlen("abc"))
		return (0);
	else
		return (-1);
}
