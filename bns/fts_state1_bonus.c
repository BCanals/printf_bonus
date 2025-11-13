/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_state1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:33 by becanals          #+#    #+#             */
/*   Updated: 2025/11/06 19:06:05 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_new_string(t_parser *parser)
{
	char	*str;
	size_t	i;
	t_list	*new;

	if (parser->format[0] == 0)
		parser->state = FINISH;
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
			return (parser->kill = 1, (void)0);
		new = ft_lstnew(str);
		if (!new)
			return (parser->kill = 1, (void)0);
		ft_lstadd_back(&(parser->output), new);
		(parser->format) += i;
	}
}

void	ft_forced_string(t_parser *parser)
{
	int		i;
	char	*str;
	t_list	*new;

	while (parser->format[0] != '%')
		parser->format--;
	i = 0;
	while (parser->format[++i] && parser->format[i] != '%')
		;
	str = ft_strdup_n(parser->format, i);
	if (!str)
		return (parser->kill = 1, (void)0);
	new = ft_lstnew(str);
	if (!new)
		return (parser->kill = 1, (void)0);
	ft_lstadd_back(&(parser->output), new);
	(parser->format) += i;
	parser->state = NEW_STRING;
}

void	ft_format_flag(t_parser *parser)
{
	if (ft_strchr("#0- +", parser->format[0]))
	{
		if (parser->format[0] == '#')
			parser->flag_hash = 1;
		else if (parser->format[0] == ' ' && !parser->flag_sign
			&& parser->flag_sign != 3)
			parser->flag_sign = 1;
		else if (parser->format[0] == '+' && parser->flag_sign != 3)
			parser->flag_sign = 2;
		else if (parser->format[0] == '0' && !parser->flag_zer_min)
			parser->flag_zer_min = 1;
		else if (parser->format[0] == '-')
			parser->flag_zer_min = 2;
		parser->format++;
		return ;
	}
	parser->state = FORMAT_F_LEN;
}

void	ft_format_f_len(t_parser *parser)
{
	if (ft_isdigit(parser->format[0]))
	{
		parser->flag_len = ft_atou(parser->format);
		if (parser->flag_len > 2147483647)
			return (parser->kill = 1, (void)0);
		while (ft_isdigit(parser->format[0]))
			parser->format++;
	}
	parser->state = FORMAT_PRECISION;
}

void	ft_format_precision(t_parser *parser)
{
	if (parser->format[0] == '.')
	{
		parser->precision = 1;
		if (parser->flag_zer_min == 1)
			parser->flag_zer_min = 0;
		parser->format++;
		if (ft_isdigit(parser->format[0]))
		{
			parser->prec_len = ft_atou(parser->format);
			if (parser->prec_len > 2147483647)
				return (parser->kill = 1, (void)0);
			while (ft_isdigit(parser->format[0]))
				parser->format++;
		}
	}
	parser->state = FORMAT_CONVER;
}
