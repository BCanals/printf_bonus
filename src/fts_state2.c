/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_state2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:16:25 by becanals          #+#    #+#             */
/*   Updated: 2025/10/26 20:53:04 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_format_p_len(t_parser *parser)
{
	if (ft_isdigit(parser->format[0]))
	{
		//falta gestionar pel cas mes gran que int amb un my_ft_atoi
		parser->prec_len = ft_atoi(parser->format);
		while (ft_isdigit(parser->format[0]))
			parser->format++;
	}
	parser->state = FORMAT_CONVER;
}

void	ft_format_conver(t_parser *parser)
{
	ft_putstr_fd("looking for the format conversion char\n", 1);
	ft_putchar_fd((parser->format)[0], 1);
	ft_putchar_fd(10, 1);
	ft_putstr_fd("Position: ", 1);
	ft_putnbr_fd(ft_memchr_pos("cspdiuxX%", parser->format[0], 9), 1);
	ft_putchar_fd(10, 1);
	parser->cvt_fts_array[ft_memchr_pos("cspdiuxX%", parser->format[0], 9)]
		(parser);
	ft_lstadd_back(&(parser->output), ft_lstnew(parser->wop));
	parser->wop = NULL;
	parser->state = NEW_STRING;
	(parser->format)++;
}
/*
void	ft_create_substr(t_parser *parser)
{
}*/
