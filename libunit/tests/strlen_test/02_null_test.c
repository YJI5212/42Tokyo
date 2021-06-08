#include "strlen_test.h"

int	strlen_02_null_test(void)
{
	if (strlen("") == ft_strlen(""))
		return (0);
	else
		return (-1);
}
