#ifndef STRLEN_TEST_H
# define STRLEN_TEST_H

# include "../tests.h"
# include "../../framework/framework.h"
# include <string.h>

int	strlen_01_basic_test(void);
int	strlen_02_null_test(void);
int	strlen_03_long_string_test(void);
int	strlen_04_segv_test(void);

#endif
