/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_convert1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:27:40 by becanals          #+#    #+#             */
/*   Updated: 2025/10/21 19:33:48 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_convert_c(t_parser *parser)
{
	ft_putstr_fd("converting from char\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
}

void	ft_convert_s(t_parser *parser)
{
	ft_putstr_fd("converting from string\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
}

void	ft_convert_p(t_parser *parser)
{
	ft_putstr_fd("converting from pointer\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
}

void	ft_convert_d(t_parser *parser)
{
	ft_putstr_fd("converting from decimal\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
}

void	ft_convert_i(t_parser *parser)
{
	ft_putstr_fd("converting from integer\n", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
}
