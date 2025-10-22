/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:01:10 by becanals          #+#    #+#             */
/*   Updated: 2025/10/22 18:20:13 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	stt_fts_constr(void (*(*array))(t_parser *))
{
	array[1] = &ft_new_string;
	array[2] = &ft_forced_string;
	array[3] = &ft_format_flag;
	array[4] = &ft_format_f_len;
	array[5] = &ft_format_precision;
	array[6] = &ft_format_p_len;
	array[7] = &ft_format_conver;
}

static void	cvt_fts_constr(void (*(*array))(t_parser *))
{
	array[0] = ft_convert_c;
	array[1] = ft_convert_s;
	array[2] = ft_convert_p;
	array[3] = ft_convert_d;
	array[4] = ft_convert_i;
	array[5] = ft_convert_u;
	array[6] = ft_convert_xl;
	array[7] = ft_convert_xu;
	array[8] = ft_convert_percent;
}

t_parser	*parser_constr(const char *format, va_list *args)
{
	t_parser	*parser;

	parser = ft_calloc(sizeof(t_parser), 1);
	if (!parser)
		return (NULL);
	parser->format = format;
	parser->args = args;
	parser->state = NEW_STRING;
	parser->stt_fts_array = ft_calloc(sizeof(void (*)(t_parser *)), 8);
	parser->cvt_fts_array = ft_calloc(sizeof(void (*)(t_parser *)), 9);
	if (!(parser->stt_fts_array) || !(parser->cvt_fts_array))
	{
		clean_up(parser, args);
		return (NULL);
	}
	stt_fts_constr(parser->stt_fts_array);
	cvt_fts_constr(parser->cvt_fts_array);
	return (parser);
}
