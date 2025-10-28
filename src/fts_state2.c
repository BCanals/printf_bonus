/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_state2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:16:25 by becanals          #+#    #+#             */
/*   Updated: 2025/10/28 10:47:19 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_reset_flags(t_parser *parser)
{
	parser->flag_converter = 0;
	parser->flag_hash = 0;
	parser->flag_spc_pls = 0;
	parser->flag_min_zer = 0;
	parser->flag_len = 0;
	parser->precision = 0;
	parser->prec_len = 0;
	parser->wop = NULL;
}

static void	ft_expansion(t_parser *parser)
{
	
}

void	ft_format_conver(t_parser *parser)
{
	ft_putstr_fd("looking for the format conversion char\n", 1);
	ft_putchar_fd((parser->format)[0], 1);
	ft_putchar_fd(10, 1);
	ft_putstr_fd("Position: ", 1);
	ft_putnbr_fd(ft_memchr_pos("cspdiuxX%", parser->format[0], 9), 1);
	ft_putchar_fd(10, 1);
	
	if (ft_memchr_pos("cspdiuxX", parser->format[0], 8) == -1)
	{
		ft_reset_flags(parser);
		parser->state = FORCED_STRING;
		return ;
	}
	parser->cvt_fts_array[ft_memchr_pos("cspdiuxX%", parser->format[0], 9)]
		(parser);
	parser->flag_converter = parser->format[0];
	//aqui va l'expansio de la cadena, en lloc d'aquesta linia
	ft_lstadd_back(&(parser->output), ft_lstnew(parser->wop));
	ft_reset_flags(parser);
	parser->state = NEW_STRING;
	(parser->format)++;
}
/*
void	ft_create_substr(t_parser *parser)
{
}*/
