#include "strlen_test.h"

int	strlen_launcher(void)
{
	t_all_tests	t;

	t.pass_test_num = 0;
	t.total_test_num = 0;
	printf("FT_STRLEN:\n");
	load_test(&t, "Basic test", &strlen_01_basic_test, OK);
	load_test(&t, "NULL test", &strlen_02_null_test, OK);
	load_test(&t, "Long string test", &strlen_03_long_string_test, OK);
	load_test(&t, "SEGV test", &strlen_04_segv_test, SEGV);
	return (launch_tests(&t));
}
