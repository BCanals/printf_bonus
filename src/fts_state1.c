/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_state1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:33 by becanals          #+#    #+#             */
/*   Updated: 2025/10/22 19:01:22 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_new_string(t_parser *parser)
{
	int	i;

	ft_putstr_fd("at new string\n", 1);
	if (parser->format[0] == 0)
	{
		ft_putstr_fd("nothing to be done here\n", 1);
		parser->state = FINISH;
	}
	else if ((parser->format)[0] == '%')
	{
		parser->format++;
		parser->state = FORMAT_FLAG;
	}
	else
	{
		i = -1;
		while ((parser->format)[++i] && (parser->format)[i] != '%')
			;
		(parser->format) += i;
	}
}

void	ft_forced_string(t_parser *parser)
{
	while (parser->format[0] != '%')
		parser->format--;
	ft_putstr_fd("forcing string starting at: ", 1);
	write(1, parser->format, 5);
	ft_putchar_fd("/n");
	parser->format++;
	while (parser->format[0] != '%')
		parser->format++;
	parser->state = NEW_STRING;
}

void	ft_format_flag(t_parser *parser)
{
	ft_putstr_fd("looking for a format flag\n", 1);
	if (ft_strchr("#0- +", parser->format[0]))
	{
		ft_putstr_fd("taking a flag\n", 1);
		ft_putchar_fd(parser->format[0], 1);
		ft_putchar_fd(10, 1);
		parser->format++;
		return ;
	}
	parser->state = FORMAT_F_LEN;
}

void	ft_format_f_len(t_parser *parser)
{
	if (ft_isdigit(parser->format[0]))
	{
		//falta gestionar pel cas mes gran que int amb un my_ft_atoi
		parser->flag_len = ft_atoi(parser->format);
		while (ft_isdigit(parser->format[0]))
			parser->format++;
	}
	parser->state = FORMAT_PRECISION;
}

void	ft_format_precision(t_parser *parser)
{
	ft_putstr_fd("looking for format precision\n", 1);
	if (parser->format[0] == '.')
	{
		ft_putstr_fd("precision: yes\n", 1);
		parser->format++;
		while (ft_isdigit(parser->format[0]))
			parser->format++;
	}
	parser->state = FORMAT_P_LEN;
}
