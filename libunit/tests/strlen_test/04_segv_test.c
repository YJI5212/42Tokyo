#include "strlen_test.h"

int	strlen_04_segv_test(void)
{
	ft_strlen(NULL);
	return (-1);
}
