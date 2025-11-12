/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:23:34 by becanals          #+#    #+#             */
/*   Updated: 2025/11/12 18:09:08 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_printf.h"

int main(int argc, char **argv)
{

	int	mine;
	int	syst;

	if (argc == 1 || ft_memchr(argv[1], 'c', ft_strlen(argv[1])))
	{
		mine = ft_printf("%c!\n", 65);
		syst = printf("%c!\n", 65);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%12c!\n", 65);
		syst = printf("%12c!\n", 65);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.12c!\n", 65);
		syst = printf("%.12c!\n", 65);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%12.10c!\n", 65);
		syst = printf("%12.10c!\n", 65);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%8c!\n", 0);
		syst = printf("%8c!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%c!\n", 0);
		syst = printf("%c!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.8c!\n", 0);
		syst = printf("%.8c!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%c, %c!\n", 0, 0);
		syst = printf("%c, %c!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%8c!\n", 129);
		syst = printf("%8c!\n", 129);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%8c!\n", -5);
		syst = printf("%8c!\n", -5);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%8c!\n", 2147483649);
		syst = printf("%8c!\n", 2147483649);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
	}
	if (argc == 1 || ft_memchr(argv[1], 's', ft_strlen(argv[1])))
	{
		ft_putstr_fd("bloc 1\n", 1);
		mine = ft_printf("%8s!\n", "");
		syst = printf("%8s!\n", "");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.8s!\n", "");
		syst = printf("%.8s!\n", "");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%10.8s!\n", "");
		syst = printf("%10.8s!\n", "");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%8.12s!\n", "");
		syst = printf("%8.12s!\n", "");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		ft_putstr_fd("bloc 2\n", 1);
		mine = ft_printf("%8s!\n", ".");
		syst = printf("%8s!\n", ".");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.8s!\n", ".");
		syst = printf("%.8s!\n", ".");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%10.8s!\n", ".");
		syst = printf("%10.8s!\n", ".");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%8.12s!\n", ".");
		syst = printf("%8.12s!\n", ".");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		ft_putstr_fd("bloc 3\n", 1);
		mine = ft_printf("%8s!\n", "ABCDEF\0GHIJ");
		syst = printf("%8s!\n", "ABCDEF\0GHIJ");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.8s!\n", "ABCDEF\0GHIJ");
		syst = printf("%.8s!\n", "ABCDEF\0GHIJ");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%10.8s!\n", "ABCDEF\0GHIJ");
		syst = printf("%10.8s!\n", "ABCDEF\0GHIJ");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%8.12s!\n", "ABCDEF\0GHIJ");
		syst = printf("%8.12s!\n", "ABCDEF\0GHIJ");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		ft_putstr_fd("bloc 4\n", 1);
		mine = ft_printf("%8s!\n", "ABCDEF\127GHIJ");
		syst = printf("%8s!\n", "ABCDEF\127GHIJ");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%10.8s!\n", "ABCDEF\127GHIJ");
		syst = printf("%10.8s!\n", "ABCDEF\127GHIJ");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%8.12s!\n", "ABCDEF\127GHIJ");
		syst = printf("%8.12s!\n", "ABCDEF\127GHIJ");
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
	}
	if (argc == 1 || ft_memchr(argv[1], 'p', ft_strlen(argv[1])))
	{
		mine = ft_printf("%8p!\n", 0);
		syst = printf("%8p!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		char	*str = "";
		mine = ft_printf("%p!\n", str);
		syst = printf("%p!\n", str);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%20p!\n", str);
		syst = printf("%20p!\n", str);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%20p!\n", -1);
		syst = printf("%20p!\n", -1);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%20p!\n", 0xFFffFFff + 1);
		syst = printf("%20p!\n", 0xFFffFFff + 1);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
	}
	// 'd' is the same as 'i'
	if (argc == 1 || ft_memchr(argv[1], 'd', ft_strlen(argv[1])) || ft_memchr(argv[1], 'i', ft_strlen(argv[1])))
	{
		ft_putstr_fd("bloc 2:\n", 1);
		mine = ft_printf("%d!\n", 0);
		syst = printf("%d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%d!\n", -2147483648);
		syst = printf("%d!\n", -2147483648);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%d!\n", 2147483648);
		syst = printf("%d!\n", 2147483648);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%d!\n", 0xFFffFFff);
		syst = printf("%d!\n", 0xFFffFFff);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%20d!\n", 123456789);
		syst = printf("%20d!\n", 123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%2d!\n", 123456789);
		syst = printf("%2d!\n", 123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%20d!\n", -123456789);
		syst = printf("%20d!\n", -123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%2d!\n", -123456789);
		syst = printf("%2d!\n", -123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.20d!\n", 0);
		syst = printf("%.20d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%20.10d!\n", 0);
		syst = printf("%20.10d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%10.20d!\n", 0);
		syst = printf("%10.20d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%10d!\n", -1234);
		syst = printf("%10d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.20d!\n", -1234);
		syst = printf("%.20d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%20.10d!\n", -1234);
		syst = printf("%20.10d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%10.20d!\n", -1234);
		syst = printf("%10.20d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		ft_putstr_fd("bloc 2:\n", 1);
		mine = ft_printf("%0d!\n", 0);
		syst = printf("%0d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0d!\n", -2147483648);
		syst = printf("%0d!\n", -2147483648);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0d!\n", 2147483648);
		syst = printf("%0d!\n", 2147483648);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0d!\n", 0xFFffFFff);
		syst = printf("%0d!\n", 0xFFffFFff);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%020d!\n", 123456789);
		syst = printf("%020d!\n", 123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%02d!\n", 123456789);
		syst = printf("%02d!\n", 123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%020d!\n", -123456789);
		syst = printf("%020d!\n", -123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%02d!\n", -123456789);
		syst = printf("%02d!\n", -123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0.20d!\n", 0);
		syst = printf("%0.20d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%020.10d!\n", 0);
		syst = printf("%020.10d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%010.20d!\n", 0);
		syst = printf("%010.20d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%010d!\n", -1234);
		syst = printf("%010d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0.20d!\n", -1234);
		syst = printf("%0.20d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%020.10d!\n", -1234);
		syst = printf("%020.10d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%010.20d!\n", -1234);
		syst = printf("%010.20d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		ft_putstr_fd("bloc 3:\n", 1);
		mine = ft_printf("%-d!\n", 0);
		syst = printf("%-d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0-d!\n", -2147483648);
		syst = printf("%0-d!\n", -2147483648);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0-d!\n", 2147483648);
		syst = printf("%0-d!\n", 2147483648);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0-d!\n", 0xFFffFFff);
		syst = printf("%0-d!\n", 0xFFffFFff);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0-20d!\n", 123456789);
		syst = printf("%0-20d!\n", 123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-02d!\n", 123456789);
		syst = printf("%-02d!\n", 123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-020d!\n", -123456789);
		syst = printf("%-020d!\n", -123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-02d!\n", -123456789);
		syst = printf("%-02d!\n", -123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-0.20d!\n", 0);
		syst = printf("%-0.20d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-020.10d!\n", 0);
		syst = printf("%-020.10d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-010.20d!\n", 0);
		syst = printf("%-010.20d!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-010d!\n", -1234);
		syst = printf("%-010d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-0.20d!\n", -1234);
		syst = printf("%-0.20d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-020.10d!\n", -1234);
		syst = printf("%-020.10d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-010.20d!\n", -1234);
		syst = printf("%-010.20d!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
	}
	if (argc == 1 || ft_memchr(argv[1], 'u', ft_strlen(argv[1])))
	{
		ft_putstr_fd("bloc 1:\n", 1);
		mine = ft_printf("%0u!\n", 0);
		syst = printf("%0u!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0u!\n", -2147483648);
		syst = printf("%0u!\n", -2147483648);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0u!\n", 2147483648);
		syst = printf("%0u!\n", 2147483648);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0u!\n", 0xFFffFFff);
		syst = printf("%0u!\n", 0xFFffFFff);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%020u!\n", 123456789);
		syst = printf("%020u!\n", 123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%02u!\n", 123456789);
		syst = printf("%02u!\n", 123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%020u!\n", -123456789);
		syst = printf("%020u!\n", -123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%02u!\n", -123456789);
		syst = printf("%02u!\n", -123456789);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0.20u!\n", 0);
		syst = printf("%0.20u!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%020.10u!\n", 0);
		syst = printf("%020.10u!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%010.20u!\n", 0);
		syst = printf("%010.20u!\n", 0);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%010u!\n", -1234);
		syst = printf("%010u!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0.20u!\n", -1234);
		syst = printf("%0.20u!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%020.10u!\n", -1234);
		syst = printf("%020.10u!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%010.20u!\n", -1234);
		syst = printf("%010.20u!\n", -1234);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%0u!\n", 0x100000000);
		syst = printf("%0u!\n", 0x100000000);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%0u!\n", 0x100000001);
		syst = printf("%0u!\n", 0x100000001);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
	}
	if (argc == 1 || ft_memchr(argv[1], 'x', ft_strlen(argv[1])))
	{
		mine = ft_printf("%x!\n", 0x600);
		syst = printf("%x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%74x!\n", 0x600);
		syst = printf("%74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.74x!\n", 0x600);
		syst = printf("%.74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%10.24x!\n", 0x600);
		syst = printf("%10.24x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%#x!\n", 0x600);
		syst = printf("%#x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%#74x!\n", 0x600);
		syst = printf("%#74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%#.74x!\n", 0x600);
		syst = printf("%#.74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%#10.24x!\n", 0x600);
		syst = printf("%#10.24x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%0x!\n", 0x600);
		syst = printf("%0x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%074x!\n", 0x600);
		syst = printf("%074x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0.74x!\n", 0x600);
		syst = printf("%0.74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%010.24x!\n", 0x600);
		syst = printf("%010.24x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%0#x!\n", 0x600);
		syst = printf("%0#x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0#74x!\n", 0x600);
		syst = printf("%0#74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0#.74x!\n", 0x600);
		syst = printf("%0#.74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0#10.24x!\n", 0x600);
		syst = printf("%0#10.24x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%-x!\n", 0x600);
		syst = printf("%-x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-74x!\n", 0x600);
		syst = printf("%-74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-.74x!\n", 0x600);
		syst = printf("%-.74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-10.24x!\n", 0x600);
		syst = printf("%-10.24x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%-#x!\n", 0x600);
		syst = printf("%-#x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-#74x!\n", 0x600);
		syst = printf("%-#74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-#.74x!\n", 0x600);
		syst = printf("%-#.74x!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-#10.24x!\n", 0xFFFFFFFFFFFF);
		syst = printf("%-#10.24x!\n", 0xFFFFFFFFFFFF);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
	}
	if (argc == 1 || ft_memchr(argv[1], 'X', ft_strlen(argv[1])))
	{
		mine = ft_printf("%X!\n", 0x600);
		syst = printf("%X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%74X!\n", 0x600);
		syst = printf("%74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%.74X!\n", 0x600);
		syst = printf("%.74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%10.24X!\n", 0x600);
		syst = printf("%10.24X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%#X!\n", 0x600);
		syst = printf("%#X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%#74X!\n", 0x600);
		syst = printf("%#74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%#.74X!\n", 0x600);
		syst = printf("%#.74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%#10.24X!\n", 0x600);
		syst = printf("%#10.24X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%0X!\n", 0x600);
		syst = printf("%0X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%074X!\n", 0x600);
		syst = printf("%074X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0.74X!\n", 0x600);
		syst = printf("%0.74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%010.24X!\n", 0x600);
		syst = printf("%010.24X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%0#X!\n", 0x600);
		syst = printf("%0#X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0#74X!\n", 0x600);
		syst = printf("%0#74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0#.74X!\n", 0x600);
		syst = printf("%0#.74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%0#10.24X!\n", 0x600);
		syst = printf("%0#10.24X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%-X!\n", 0x600);
		syst = printf("%-X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-74X!\n", 0x600);
		syst = printf("%-74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-.74X!\n", 0x600);
		syst = printf("%-.74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-10.24X!\n", 0x600);
		syst = printf("%-10.24X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
		
		mine = ft_printf("%-#X!\n", 0x600);
		syst = printf("%-#X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-#74X!\n", 0x600);
		syst = printf("%-#74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-#.74X!\n", 0x600);
		syst = printf("%-#.74X!\n", 0x600);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);

		mine = ft_printf("%-#10.24X!\n", 0xFFFFFFFFFFFF);
		syst = printf("%-#10.24X!\n", 0xFFFFFFFFFFFF);
		if (mine != syst)
			ft_putstr_fd("====> RETURN ERROR<====", 1);
	}
}
