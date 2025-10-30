/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_state1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:33 by becanals          #+#    #+#             */
/*   Updated: 2025/10/30 16:24:41 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_new_string(t_parser *parser)
{
	char	*str;
	size_t	i;

	//ft_putstr_fd("at new string\n", 1);
	if (parser->format[0] == 0)
	{
	//	ft_putstr_fd("nothing to be done here\n", 1);
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
		str = ft_strdup_n(parser->format, i);
		if (!str)
			return (clean_up(parser, parser->args));
		ft_lstadd_back(&(parser->output), ft_lstnew(str));
		(parser->format) += i;
	}
}

void	ft_forced_string(t_parser *parser)
{
	int		i;
	char	*str;

	while (parser->format[0] != '%')
		parser->format--;
	//ft_putstr_fd("forcing string\n", 1);
	i = 0;
	while (parser->format[++i] && parser->format[i] != '%')
		;
	str = ft_strdup_n(parser->format, i);
	if (!str)
		return (clean_up(parser, parser->args));
	ft_lstadd_back(&(parser->output), ft_lstnew(str));
	(parser->format) += i;
	parser->state = NEW_STRING;
}

void	ft_format_flag(t_parser *parser)
{
	//ft_putstr_fd("\nlooking for a format flag with: ", 1);
	//ft_putchar_fd(parser->format[0], 1);
	//ft_putstr_fd("\n", 1);
	if (ft_strchr("#0- +", parser->format[0]))
	{
		//ft_putstr_fd("taking a flag\n", 1);
		//ft_putchar_fd(parser->format[0], 1);
		//ft_putchar_fd(10, 1);
		if (parser->format[0] == '#')
			parser->flag_hash = 1;
		else if (parser->format[0] == ' ' && !parser->flag_spc_pls)
			parser->flag_spc_pls = 1;
		else if (parser->format[0] == '+')
			parser->flag_spc_pls = 2;
		else if (parser->format[0] ==  '0' && !parser->flag_zer_min)
			parser->flag_zer_min = 1;
		else if (parser->format[0] == '-')
			parser->flag_zer_min = 2;
		//ft_const_printer(parser);
		parser->format++;
		return ;
	}
	parser->state = FORMAT_F_LEN;
	//ft_const_printer(parser);
}

void	ft_format_f_len(t_parser *parser)
{
	//ft_putstr_fd("\nlooking for a format length  with: ", 1);
	//ft_putchar_fd(parser->format[0], 1);
	//ft_putstr_fd("\n", 1);
	if (ft_isdigit(parser->format[0]))
	{
		//falta gestionar pel cas mes gran que int amb un my_ft_atoi
		parser->flag_len = ft_atoi(parser->format);
		while (ft_isdigit(parser->format[0]))
			parser->format++;
	}
	//ft_const_printer(parser);
	parser->state = FORMAT_PRECISION;
}

void	ft_format_precision(t_parser *parser)
{
	//ft_putstr_fd("\nlooking for format precision\n", 1);
	if (parser->format[0] == '.')
	{
		//ft_putstr_fd("precision: yes\n", 1);
		parser->precision = 1;
		if (parser->flag_zer_min == 1)
			parser->flag_zer_min = 0;
		parser->format++;
		if (ft_isdigit(parser->format[0]))
		{
			//falta gestionar pel cas mes gran que int amb un my_ft_atoi
			parser->prec_len = ft_atoi(parser->format);
			while (ft_isdigit(parser->format[0]))
				parser->format++;
		}
	}
	//ft_const_printer(parser);
	parser->state = FORMAT_CONVER;
}
