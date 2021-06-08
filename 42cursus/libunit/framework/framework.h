#ifndef FRAMEWORK_H
# define FRAMEWORK_H

# include <stdio.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>

# define IS_TIMEOUT		1
# define TIMEOUT_SEC	5

# define MAX_TEST_NUM	100

# define GREEN	"\x1b[32m"
# define RED	"\x1b[31m"
# define RESET	"\x1b[39m"

# define OK			0
# define NG			-1
# define SEGV		-2
# define BUSE		-3
# define TIMEOUT	-4
# define OTHER		-5

typedef struct s_unit_test
{
	char	*func_name;
	int		(*func)(void);
	int		correct_status;
	int		result;
}	t_unit_test;

typedef struct s_all_tests
{
	t_unit_test	test[MAX_TEST_NUM];
	int			pass_test_num;
	int			total_test_num;
}	t_all_tests;

void	load_test(t_all_tests *t, char *test_name, int (*func)(void), int sta);
int		launch_tests(t_all_tests *t);

#endif
