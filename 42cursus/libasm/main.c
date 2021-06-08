#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <errno.h>

#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[39m"

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void	test_strlen(void)
{
	const char	*s1;

	printf(GREEN"\nCHECK ft_strlen ...\n"RESET);
	/*
	**Normal Test 1...Empty String
	*/
	printf(BLUE"< Normal Test 1 > ... Empty String\n"RESET);
	s1 = "";
	printf("s1:%s\n    ft_:%zu\n", s1, ft_strlen(s1));
	printf("origial:%zu\n", strlen(s1));
	/*
	**Normal Test 2...Very long String
	*/
	printf(BLUE"< Normal Test 2 > ... Very long String\n"RESET);
	s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printf("s1:%s\n     ft_:%zu\n", s1, ft_strlen(s1));
	printf("origial:%zu\n", strlen(s1));
}

void	test_strcpy(void)
{
	const char	*s2;
	char		buf1[128];
	char		buf2[256];
	char		*tmp;

	printf(GREEN"\nCHECK ft_strcpy ...\n"RESET);
	/*
	**Normal Test 1...Empty String
	*/
	printf(BLUE"< Normal Test 1 > ... Empty String\n"RESET);
	s2 = "";
	printf("before copy:%s\n", buf1);
	tmp = ft_strcpy(buf1, s2);
	printf(" after copy:%s\n", tmp);
	/*
	**Normal Test 2...Very long String
	*/
	printf(BLUE"< Normal Test 2 > ... Very long String\n"RESET);
	s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printf("before copy:%s\n", buf2);
	tmp = ft_strcpy(buf2, s2);
	printf(" after copy:%s\n", tmp);
}

void	test_strcmp(void)
{
	const char	*s1;
	const char	*s2;
	int			ret1;
	int			ret2;

	printf(GREEN"\nCHECK ft_strcmp ...\n"RESET);
	/*
	**Normal Test 1...2 Empty String
	*/
	printf(BLUE"< Normal Test 1 > ... 2 Empty String\n"RESET);
	s1 = "";
	s2 = "";
	ret1 = strcmp(s1, s2);
	ret2 = ft_strcmp(s1, s2);
	printf("s1:%s, s2:%s\n original:%d, ft_:%d\n", s1, s2, ret1, ret2);
	/*
	**Normal Test 2...1st is Empty String
	*/
	printf(BLUE"< Normal Test 2 > ... 1st is Empty String\n"RESET);
	s1 = "";
	s2 = "abc";
	ret1 = strcmp(s1, s2);
	ret2 = ft_strcmp(s1, s2);
	printf("s1:%s, s2:%s\n original:%d, ft_:%d\n", s1, s2, ret1, ret2);
	/*
	**Normal Test 3...2nd is Empty String
	*/
	printf(BLUE"< Normal Test 3 > ... 2nd is Empty String\n"RESET);
	s1 = "";
	s2 = "abc";
	ret1 = strcmp(s1, s2);
	ret2 = ft_strcmp(s1, s2);
	printf("s1:%s, s2:%s\n original:%d, ft_:%d\n", s1, s2, ret1, ret2);
	/*
	**Normal Test 4...multiple
	*/
	printf(BLUE"< Normal Test 4 > ... multiple\n"RESET);
	s1 = "abcdef";
	s2 = "abc";
	ret1 = strcmp(s1, s2);
	ret2 = ft_strcmp(s1, s2);
	printf("s1:%s, s2:%s\n original:%d, ft_:%d\n", s1, s2, ret1, ret2);
}

void	test_write(void)
{
	const char	*s1;
	ssize_t		ret1;
	ssize_t		ret2;

	printf(GREEN"CHECK ft_write ...\n"RESET);
	/*
	**Normal Test
	*/
	printf(BLUE"< Normal Test >\n"RESET);
	s1 = "a\n";
	errno = 0;
	printf("ft_:");
	ret1 = ft_write(1, s1, 2);
	printf("-------->ret:%zd, errno:%d\n", ret1, errno);
	errno = 0;
	printf("original:");
	ret2 = write(1, s1, 2);
	printf("-------->ret:%zd, errno:%d\n", ret2, errno);
	/*
	**Error Test
	*/
	printf(BLUE"< Error Test >\n"RESET);
	s1 = NULL;
	errno = 0;
	printf("ft_:");
	ret1 = ft_write(1, s1, 2);
	printf("     -------->ret:%zd, errno:%d\n", ret1, errno);
	errno = 0;
	printf("original:");
	ret2 = write(1, s1, 2);
	printf("-------->ret:%zd, errno:%d\n", ret2, errno);
}

void	test_read(void)
{
	char	buf1[128];
	char	buf2[128];
	int		len;

	printf(GREEN"\nCHECK ft_read ...\n"RESET);
	/*
	**Normal Test
	*/
	printf(BLUE"< Normal Test >\n"RESET);
	errno = 0;
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));
	len = read(open("./file.txt", O_RDONLY), buf1, 100);
	printf("*original\ncont:%slen:%d, errno:%d\n", buf1, len, errno);
	errno = 0;
	len = ft_read(open("./file.txt", O_RDONLY), buf2, 100);
	printf("*ft_\ncont:%slen:%d, errno:%d\n", buf2, len, errno);
	/*
	**Stdin Test
	*/
	printf(BLUE"< Stdin Test >\n"RESET);
	errno = 0;
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));
	len = read(1, buf1, 100);
	printf("*original\ncont:%s, len:%d, errno:%d\n", buf1, len, errno);
	errno = 0;
	len = ft_read(1, buf2, 100);
	printf("*ft_\ncont:%s, len:%d, errno:%d\n", buf2, len, errno);
	/*
	**Error Test
	*/
	printf(BLUE"< Error Test >\n"RESET);
	errno = 0;
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));
	len = read(-1, buf1, 100);
	printf("*orignal\nlen:%d, errno:%d\n", len, errno);
	errno = 0;
	len = ft_read(-1, buf2, 100);
	printf("*ft_\nlen:%d, errno:%d\n", len, errno);
}

void	test_strdup(void)
{
	const char	*s1;
	char		*new_org;
	char		*new_ft;

	printf(GREEN"\nCHECK ft_strdup ...\n"RESET);
	/*
	**Normal Test 1...Empty
	*/
	printf(BLUE"< Normal Test 1 > ... Empty\n"RESET);
	s1 = "";
	new_org = strdup(s1);
	new_ft = ft_strdup(s1);
	printf("s1:%s\n original:%s\n      ft_:%s\n", s1, new_org, new_ft);
	/*
	**Normal Test 2...Very long
	*/
	printf(BLUE"< Normal Test 2 > ... Very long\n"RESET);
	s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	new_org = strdup(s1);
	new_ft = ft_strdup(s1);
	printf("s1:%s\n original:%s\n      ft_:%s\n", s1, new_org, new_ft);
}

int	main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	/*
	**ft_strlen
	*/
	test_strlen();
	/*
	**ft_strcpy
	*/
	test_strcpy();
	/*
	**ft_strcmp
	*/
	test_strcmp();
	/*
	**ft_write
	*/
	test_write();
	/*
	**ft_read
	*/
	test_read();
	/*
	**ft_strdup
	*/
	test_strdup();
	return (0);
}
