#ifndef ATOI_TEST_H
# define ATOI_TEST_H

# include "../tests.h"
# include "../../framework/framework.h"
# include <stdlib.h>

int	atoi_01_basic_test(void);
int	atoi_02_null_test(void);
int	atoi_03_max_int_test(void);
int	atoi_04_min_int_test(void);
int	atoi_05_negative_test(void);
int	atoi_06_positive_test(void);
int	atoi_07_non_numeric_test(void);
int	atoi_08_double_plus_test(void);
int	atoi_09_double_minus_test(void);
int	atoi_10_character_test(void);
int	atoi_11_space_insertion_test(void);

#endif
