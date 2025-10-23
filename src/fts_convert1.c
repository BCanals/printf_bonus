/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_convert1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:27:40 by becanals          #+#    #+#             */
/*   Updated: 2025/10/23 18:35:05 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_convert_c(t_parser *parser)
{
	char	*c;

	ft_putstr_fd("converting from char\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);

	c = ft_calloc(2, 1);
	if (!c)
		return (clean_up(parser, parser->args));
	c[0] = va_arg(*(parser->args), int);
	parser->wop = c;
}

void	ft_convert_s(t_parser *parser)
{
	char	*str;
	ft_putstr_fd("converting from string\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
	str = va_arg(*(parser->args), char *);
	if (!str)
		str = ft_strdup("(nil)");
	if (!str)
		return (clean_up(parser, parser->args));
	parser->wop = str;
}

void	ft_convert_p(t_parser *parser)
{
	void	*ptr;
	ft_putstr_fd("converting from pointer\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
	ptr = va_arg(*(parser->args), void *);
	if (!ptr)
		ptr = ft_strdup("(nil)");
	if (!ptr)
		return (clean_up(parser, parser->args));
	parser->wop = ptr;
}

void	ft_convert_d(t_parser *parser)
{
	char	*num;
	ft_putstr_fd("converting from decimal/int\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
	num = ft_itoa(va_arg(*(parser->args), int));
	if (!num)
		return (clean_up(parser->args));
	parser->wop = num;
}
