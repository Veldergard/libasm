/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:40:24 by olaurine          #+#    #+#             */
/*   Updated: 2020/10/26 17:57:21 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define FT_STR "test string test string test string test string test string"
#define FT_LSTR FT_STR FT_STR FT_STR FT_STR FT_STR FT_STR FT_STR FT_STR FT_STR
#define FT_LLSTR FT_LSTR FT_LSTR FT_LSTR FT_LSTR FT_LSTR FT_LSTR FT_LSTR FT_LSTR

void	test_len()
{
	char *s1 = "test";
	char *s2 = "";
	printf("------FT_STRLEN TESTING------\n");
	printf("string = %s\nSYS - %zu\n FT - %zu\n\n", s1, strlen(s1), ft_strlen(s1));
	printf("string = %s\nSYS - %zu\n FT - %zu\n\n", s2, strlen(s2), ft_strlen(s2));
	printf("string = %s\nSYS - %zu\n FT - %zu\n\n", FT_LLSTR, strlen(FT_LLSTR), ft_strlen(FT_LLSTR));
	printf("-------------END-------------\n\n\n\n\n\n");
}

void	test_cpy()
{
	printf("------FT_STRCPY TESTING------\n");
	printf("-------------END-------------\n\n\n\n\n\n");
}

void	test_cmp()
{
	printf("------FT_STRCMP TESTING------\n");
	printf("-------------END-------------\n\n\n\n\n\n");
}

void	test_write()
{
	int fd1 = open("wr_test1.txt", O_WRONLY);
	int fd2 = open("wr_test2.txt", O_WRONLY);
	ssize_t ret;

	printf("------FT_WRITE TESTING------\n");
	errno = 0;
	ret = write(fd1, "lol", 3);
	printf("SYS Ret: %zd, errno: %d\n", ret, errno);
	errno = 0;
	ret = ft_write(fd2, "lol", 3);
	printf("FT  Ret: %zd, errno: %d\n\n", ret, errno);
	close(fd1);
	close(fd2);


	errno = 0;
	ret = write(-1, "test", 4);
	printf("SYS Ret: %zd, errno: %d\n", ret, errno);
	errno = 0;
	ret = ft_write(-1, "test", 4);
	printf("FT  Ret: %zd, errno: %d\n\n", ret, errno);


	errno = 0;
	ret = write(1, "test", 4);
	printf("SYS Ret: %zd, errno: %d\n", ret, errno);
	errno = 0;
	ret = ft_write(1, "test", 4);
	printf("FT  Ret: %zd, errno: %d\n", ret, errno);
	printf("-------------END------------\n\n\n\n\n\n");
}

void	test_read()
{
	int fd1 = open("ft_read.s", O_RDONLY);
	int fd2 = open("ft_read.s", O_RDONLY);
	char buf[100];
	ssize_t ret;


	printf("-------FT_READ TESTING-------\n");
	errno = 0;
	while ((ret = read(fd1, buf, 99)) > 0)
	{
		buf[ret] = 0;
		printf("read: %zd - %s\n", ret, buf);
	}
	printf("SYS Ret: %zd, errno: %d\n", ret, errno);
	errno = 0;
	while ((ret = ft_read(fd2, buf, 99)) > 0)
	{
		buf[ret] = 0;
		printf("ft_read: %zd - %s\n", ret, buf);
	}
	printf("FT  Ret: %zd, errno: %d\n\n", ret, errno);
	close(fd1);
	close(fd2);


	errno = 0;
	while ((ret = read(-1, buf, 99)) > 0)
	{
		buf[ret] = 0;
		printf("read: %zd - %s\n", ret, buf);
	}
	printf("SYS Ret: %zd, errno: %d\n", ret, errno);
	errno = 0;
	while ((ret = ft_read(-1, buf, 99)) > 0)
	{
		buf[ret] = 0;
		printf("ft_read: %zd - %s\n", ret, buf);
	}
	printf("FT  Ret: %zd, errno: %d\n\n", ret, errno);


	errno = 0;
	while ((ret = read(0, buf, 99)) > 0)
	{
		buf[ret] = 0;
		printf("read: %zd - %s\n", ret, buf);
	}
	printf("SYS Ret: %zd, errno: %d\n", ret, errno);
	errno = 0;
	while ((ret = ft_read(0, buf, 99)) > 0)
	{
		buf[ret] = 0;
		printf("ft_read: %zd - %s\n", ret, buf);
	}
	printf("FT  Ret: %zd, errno: %d\n\n", ret, errno);
	printf("-------------END-------------\n\n\n\n\n\n");
}

void	test_dup()
{
	printf("-------FT_STRDUP TESTING-------\n");
	printf("--------------END--------------\n");
}

int		main()
{
	test_len();
	test_cpy();
	test_cmp();
	test_write();
	test_read();
	test_dup();
}
