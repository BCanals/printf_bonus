/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:23:34 by becanals          #+#    #+#             */
/*   Updated: 2025/11/02 22:11:55 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_printf.h"

int main(int argc, char **argv)
{
	if (argc == 1 || ft_memchr(argv[1], 'c', ft_strlen(argv[1])))
	{
		ft_printf("%c!\n", 65);
		printf("%c!\n", 65);

		ft_printf("%12c!\n", 65);
		printf("%12c!\n", 65);

		ft_printf("%.12c!\n", 65);
		printf("%.12c!\n", 65);

		ft_printf("%12.10c!\n", 65);
		printf("%12.10c!\n", 65);

		ft_printf("%8c!\n", 0);
		printf("%8c!\n", 0);

		ft_printf("%8c!\n", 129);
		printf("%8c!\n", 129);

		ft_printf("%8c!\n", -5);
		printf("%8c!\n", -5);

		ft_printf("%8c!\n", 2147483649);
		printf("%8c!\n", 2147483649);
	}
	if (argc == 1 || ft_memchr(argv[1], 's', ft_strlen(argv[1])))
	{
		ft_putstr_fd("bloc 1\n", 1);
		ft_printf("%8s!\n", "");
		printf("%8s!\n", "");

		ft_printf("%.8s!\n", "");
		printf("%.8s!\n", "");
		
		ft_printf("%10.8s!\n", "");
		printf("%10.8s!\n", "");
		
		ft_printf("%8.12s!\n", "");
		printf("%8.12s!\n", "");

		ft_putstr_fd("bloc 2\n", 1);
		ft_printf("%8s!\n", ".");
		printf("%8s!\n", ".");

		ft_printf("%.8s!\n", ".");
		printf("%.8s!\n", ".");
		
		ft_printf("%10.8s!\n", ".");
		printf("%10.8s!\n", ".");
		
		ft_printf("%8.12s!\n", ".");
		printf("%8.12s!\n", ".");

		ft_putstr_fd("bloc 3\n", 1);
		ft_printf("%8s!\n", "ABCDEF\0GHIJ");
		printf("%8s!\n", "ABCDEF\0GHIJ");

		ft_printf("%.8s!\n", "ABCDEF\0GHIJ");
		printf("%.8s!\n", "ABCDEF\0GHIJ");
		
		ft_printf("%10.8s!\n", "ABCDEF\0GHIJ");
		printf("%10.8s!\n", "ABCDEF\0GHIJ");
		
		ft_printf("%8.12s!\n", "ABCDEF\0GHIJ");
		printf("%8.12s!\n", "ABCDEF\0GHIJ");

		ft_putstr_fd("bloc 4\n", 1);
		ft_printf("%8s!\n", "ABCDEF\127GHIJ");
		printf("%8s!\n", "ABCDEF\127GHIJ");
		printf("%.8s!\n", "ABCDEF\127GHIJ");
		
		ft_printf("%10.8s!\n", "ABCDEF\127GHIJ");
		printf("%10.8s!\n", "ABCDEF\127GHIJ");
		
		ft_printf("%8.12s!\n", "ABCDEF\127GHIJ");
		printf("%8.12s!\n", "ABCDEF\127GHIJ");
	}
	if (argc == 1 || ft_memchr(argv[1], 'p', ft_strlen(argv[1])))
	{
		ft_printf("%8p!\n", 0);
		printf("%8p!\n", 0);

		char	*str = "";
		ft_printf("%p!\n", str);
		printf("%p!\n", str);

		ft_printf("%20p!\n", str);
		printf("%20p!\n", str);

		ft_printf("%20p!\n", -1);
		printf("%20p!\n", -1);
		
		ft_printf("%20p!\n", 0xFFffFFff + 1);
		printf("%20p!\n", 0xFFffFFff + 1);
	}
	// 'd' is the same as 'i'
	if (argc == 1 || ft_memchr(argv[1], 'd', ft_strlen(argv[1])) || ft_memchr(argv[1], 'i', ft_strlen(argv[1])))
	{
		ft_putstr_fd("bloc 2:\n", 1);
		ft_printf("%d!\n", 0);
		printf("%d!\n", 0);

		ft_printf("%d!\n", -2147483648);
		printf("%d!\n", -2147483648);

		ft_printf("%d!\n", 2147483648);
		printf("%d!\n", 2147483648);

		ft_printf("%d!\n", 0xFFffFFff);
		printf("%d!\n", 0xFFffFFff);

		ft_printf("%20d!\n", 123456789);
		printf("%20d!\n", 123456789);

		ft_printf("%2d!\n", 123456789);
		printf("%2d!\n", 123456789);

		ft_printf("%20d!\n", -123456789);
		printf("%20d!\n", -123456789);

		ft_printf("%2d!\n", -123456789);
		printf("%2d!\n", -123456789);

		ft_printf("%.20d!\n", 0);
		printf("%.20d!\n", 0);

		ft_printf("%20.10d!\n", 0);
		printf("%20.10d!\n", 0);

		ft_printf("%10.20d!\n", 0);
		printf("%10.20d!\n", 0);

		ft_printf("%10d!\n", -1234);
		printf("%10d!\n", -1234);

		ft_printf("%.20d!\n", -1234);
		printf("%.20d!\n", -1234);

		ft_printf("%20.10d!\n", -1234);
		printf("%20.10d!\n", -1234);

		ft_printf("%10.20d!\n", -1234);
		printf("%10.20d!\n", -1234);

		ft_putstr_fd("bloc 2:\n", 1);
		ft_printf("%0d!\n", 0);
		printf("%0d!\n", 0);

		ft_printf("%0d!\n", -2147483648);
		printf("%0d!\n", -2147483648);

		ft_printf("%0d!\n", 2147483648);
		printf("%0d!\n", 2147483648);

		ft_printf("%0d!\n", 0xFFffFFff);
		printf("%0d!\n", 0xFFffFFff);

		ft_printf("%020d!\n", 123456789);
		printf("%020d!\n", 123456789);

		ft_printf("%02d!\n", 123456789);
		printf("%02d!\n", 123456789);

		ft_printf("%020d!\n", -123456789);
		printf("%020d!\n", -123456789);

		ft_printf("%02d!\n", -123456789);
		printf("%02d!\n", -123456789);

		ft_printf("%0.20d!\n", 0);
		printf("%0.20d!\n", 0);

		ft_printf("%020.10d!\n", 0);
		printf("%020.10d!\n", 0);

		ft_printf("%010.20d!\n", 0);
		printf("%010.20d!\n", 0);

		ft_printf("%010d!\n", -1234);
		printf("%010d!\n", -1234);

		ft_printf("%0.20d!\n", -1234);
		printf("%0.20d!\n", -1234);

		ft_printf("%020.10d!\n", -1234);
		printf("%020.10d!\n", -1234);

		ft_printf("%010.20d!\n", -1234);
		printf("%010.20d!\n", -1234);
	}
	if (argc == 1 || ft_memchr(argv[1], 'u', ft_strlen(argv[1])))
	{
	}
	if (argc == 1 || ft_memchr(argv[1], 'x', ft_strlen(argv[1])))
	{
		ft_printf("%74x!\n", 0x600);
		printf("%74x!\n", 0x600);

		ft_printf("%#.74x!\n", 0x600);
		printf("%#.74x!\n", 0x600);

		ft_printf("%#10.24x!\n", 0x600);
		printf("%#10.24x!\n", 0x600);
	}
	if (argc == 1 || ft_memchr(argv[1], 'X', ft_strlen(argv[1])))
	{
	}
}
