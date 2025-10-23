/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_convert2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:29:18 by becanals          #+#    #+#             */
/*   Updated: 2025/10/23 18:51:24 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_convert_u(t_parser *parser)
{
	char	*num;
	ft_putstr_fd("converting from unsigned\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
	num = ft_atoi(va_arg(*(parser->args), unsigned int));
	if (!num)
		return (clean_up(parser, parser->args));
	parser->wop = num;
}

void	ft_convert_xl(t_parser *parser)
{
	ft_putstr_fd("converting from hex (lowercase)\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
}

void	ft_convert_xu(t_parser *parser)
{
	ft_putstr_fd("converting from hex (uppercase)\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
}

void	ft_convert_percent(t_parser *parser)
{
	char	*sign;
	ft_putstr_fd("converting from percent sign\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
	sign = ft_strdup("%");
	if (!sign)
		return (clean_up(parser, parser->args));
	parser->wop = sign;
}
