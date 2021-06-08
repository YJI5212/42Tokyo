#include "framework.h"

void	load_test(t_all_tests *t, char *test_name, int (*func)(void), int sta)
{
	t->test[t->total_test_num].func_name = test_name;
	t->test[t->total_test_num].func = func;
	t->test[t->total_test_num].correct_status = sta;
	t->total_test_num++;
}

static void	fork_and_do_childprocess(t_all_tests *t, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		printf("\nFailed to fork.\n");
		exit(-1);
	}
	else if (pid == 0)
	{
		printf("   > %-28s : ", t->test[i].func_name);
		if (IS_TIMEOUT)
			alarm(TIMEOUT_SEC);
		t->test[i].result = (int)(t->test[i].func)();
		exit(t->test[i].result);
	}
}

static int	get_result(int status)
{
	int	s;

	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			s = OK;
		else
			s = NG;
	}
	else if (WIFSIGNALED(status))
	{
		if (status == SIGSEGV)
			s = SEGV;
		else if (status == SIGBUS)
			s = BUSE;
		else if (status == SIGALRM)
			s = TIMEOUT;
		else
			s = OTHER;
	}
	else
		s = OTHER;
	return (s);
}

static void	print_result(t_all_tests *t, int i, int s)
{
	if (s == t->test[i].correct_status)
	{
		printf(GREEN"[OK]\n"RESET);
		t->pass_test_num++;
	}
	else if (s == SEGV)
		printf(RED"[SEGV]\n"RESET);
	else if (s == BUSE)
		printf(RED"[BUSE]\n"RESET);
	else if (s == TIMEOUT)
		printf(RED"[TIMEOUT]\n"RESET);
	else
		printf(RED"[NG]\n"RESET);
}

int	launch_tests(t_all_tests *t)
{
	pid_t	ret_pid;
	int		i;
	int		status;

	i = 0;
	while (i < t->total_test_num)
	{
		fork_and_do_childprocess(t, i);
		ret_pid = wait(&status);
		if (ret_pid == -1)
		{
			printf("\nFailed to wait forked process.\n");
			exit(-1);
		}
		print_result(t, i, get_result(status));
		i++;
	}
	printf("%d/%d tests passed.\n\n", t->pass_test_num, t->total_test_num);
	if (t->pass_test_num < t->total_test_num)
		return (-1);
	return (0);
}
