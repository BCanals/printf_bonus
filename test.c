/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:23:34 by becanals          #+#    #+#             */
/*   Updated: 2025/10/27 20:02:35 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_printf.h"

int main(void)
{
	//char	param = 0;
	//unsigned int	param = 10;
	char *s1 = "char: %c\n str: %s\n ptr: %p\n dec: %d\n int: %i\nunsg: %u\n hex: %x\n HEX: %X\npcnt: %%\n%#24.$s";
	char *s2 = "hello world";
	int (*f1)(const char *, ...) = &ft_printf;
	//int (*f2)(const char *, ...) = &printf;
	f1(s1, 65, s2, s2, -1000, -1000, -1000, s2, s2);
	//f2(s1, &param);

	/*
	printf("%#c\n", s[0]);
	printf("%#s\n", s);
	printf("%#p\n", s);
	printf("%#+12d\n", a);
	printf("%#+12i\n", a);
	printf("%#u\n", a);
	printf("%x\n", -a);
	printf("%X\n", -a);
	printf("%-0%\n");
	*/
}


void ft_tester(char *format, void *param)
{
	ft_putstr_fd("====== NEW TEST ====\n", 1);
	ft_putstr_fd("testing: ", 1);
	ft_putstr_fd(format, 1);
	ft_putstr_fd("\n\nsystem:", 1);
	ft_putstr_fd(param, 1);
} 
