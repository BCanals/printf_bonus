/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_convert1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:27:40 by becanals          #+#    #+#             */
/*   Updated: 2025/11/06 17:43:15 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_convert_c(t_parser *parser)
{
	char	*c;

	//ft_putstr_fd("converting from char\n", 1);
	//ft_putchar_fd(parser->format[0], 1);
	//ft_putchar_fd(10, 1);

	c = ft_calloc(2, 1);
	if (!c)
		return (parser->kill = 1, (void)0);
	c[0] = va_arg(*(parser->args), int);
	parser->wop = c;
}

void	ft_convert_s(t_parser *parser)
{
	char	*str;
	char	*rtrn;

	//ft_putstr_fd("converting from string\n", 1);
	//ft_putchar_fd(parser->format[0], 1);
	//ft_putchar_fd(10, 1);
	str = va_arg(*(parser->args), char *);
	if (!str)
		rtrn = ft_strdup("(nil)");
	else
		rtrn = ft_strdup(str);
	if (!rtrn)
		return (parser->kill = 1, (void)0);
	parser->wop = rtrn;
}

void	ft_convert_p(t_parser *parser)
{
	void	*ptr;
	char	*rtrn;

	//ft_putstr_fd("converting from pointer\n", 1);
	//ft_putchar_fd(parser->format[0], 1);
	//ft_putchar_fd(10, 1);
	ptr = va_arg(*(parser->args), void *);
	if (!ptr)
		rtrn = ft_strdup("(nil)");
	else
		rtrn = ft_ptrtoa((size_t) ptr);
	if (!rtrn)
		return (parser->kill = 1, (void)0);
	parser->wop = rtrn;
}

static char	*my_ft_itoa(int num)
{
	char *atoi;
	char *unsign;

	atoi = ft_itoa(num);
	if (!atoi)
		return (NULL);
	if (num >= 0)
		return (atoi);
	unsign = ft_strdup(&atoi[1]);
	free(atoi);
	if (!unsign)
		return (NULL);
	return (unsign);
}

void	ft_convert_di(t_parser *parser)
{
	char	*str;
	int		num;
	//ft_putstr_fd("converting from decimal/int\n", 1);
	//ft_putchar_fd(parser->format[0], 1);
	//ft_putchar_fd(10, 1);
	num = va_arg(*(parser->args), int);
	if (num < 0)
		parser->flag_sign = 3;
	str = my_ft_itoa(num);
	if (!str)
		return (parser->kill = 1, (void)0);
	parser->wop = str;
}
