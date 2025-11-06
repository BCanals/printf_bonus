/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_convert2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:29:18 by becanals          #+#    #+#             */
/*   Updated: 2025/11/06 19:03:30 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_convert_u(t_parser *parser)
{
	char	*num;

	num = ft_utoa_base(va_arg(*(parser->args), unsigned int), "0123456789");
	if (!num)
		return (parser->kill = 1, (void)0);
	parser->wop = num;
}

void	ft_convert_xl(t_parser *parser)
{
	char	*num;

	num = ft_utoa_base(va_arg(*(parser->args), unsigned int),
			"0123456789abcdef");
	if (!num)
		return (parser->kill = 1, (void)0);
	parser->wop = num;
}

void	ft_convert_xu(t_parser *parser)
{
	char	*num;

	num = ft_utoa_base(va_arg(*(parser->args), unsigned int),
			"0123456789ABCDEF");
	if (!num)
		return (parser->kill = 1, (void)0);
	parser->wop = num;
}

void	ft_convert_percent(t_parser *parser)
{
	char	*sign;

	sign = ft_strdup("%");
	if (!sign)
		return (parser->kill = 1, (void)0);
	parser->wop = sign;
}
