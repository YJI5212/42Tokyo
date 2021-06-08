#include "atoi_test.h"

int	atoi_launcher(void)
{
	t_all_tests	t;

	t.pass_test_num = 0;
	t.total_test_num = 0;
	printf("FT_ATOI:\n");
	load_test(&t, "Basic test", &atoi_01_basic_test, OK);
	load_test(&t, "NULL test", &atoi_02_null_test, OK);
	load_test(&t, "Max INT test", &atoi_03_max_int_test, OK);
	load_test(&t, "Min INT test", &atoi_04_min_int_test, OK);
	load_test(&t, "Negative test", &atoi_05_negative_test, OK);
	load_test(&t, "Positive test", &atoi_06_positive_test, OK);
	load_test(&t, "Non numeric test", &atoi_07_non_numeric_test, OK);
	load_test(&t, "Double plus test", &atoi_08_double_plus_test, OK);
	load_test(&t, "Double minus test", &atoi_09_double_minus_test, OK);
	load_test(&t, "Character test", &atoi_10_character_test, OK);
	load_test(&t, "Space insertion test", &atoi_11_space_insertion_test, OK);
	return (launch_tests(&t));
}
