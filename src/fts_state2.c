/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_state2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:16:25 by becanals          #+#    #+#             */
/*   Updated: 2025/11/06 17:40:13 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_reset_flags(t_parser *parser)
{
	parser->flag_converter = 0;
	parser->flag_hash = 0;
	parser->flag_sign = 0;
	parser->flag_zer_min = 0;
	parser->flag_len = 0;
	parser->precision = 0;
	parser->prec_len = 0;
	parser->wop = NULL;
}

void	ft_format_conver(t_parser *parser)
{
	/*
	ft_putstr_fd("looking for the format conversion char\n", 1);
	ft_putchar_fd((parser->format)[0], 1);
	ft_putchar_fd(10, 1);
	ft_putstr_fd("Position: ", 1);
	ft_putnbr_fd(ft_memchr_pos("cspdiuxX%", parser->format[0], 9), 1);
	ft_putchar_fd(10, 1);
	*/
	t_list	*new;

	if (!ft_memchr("cspdiuxX", parser->format[0], 8))
	{
		ft_reset_flags(parser);
		parser->state = FORCED_STRING;
		return ;
	}
	parser->cvt_fts_array[ft_memchr_pos("cspdiuxX%", parser->format[0], 9)]
		(parser);
	parser->flag_converter = parser->format[0];
	if (!ft_expansion(parser))
		return (parser->kill = 1, (void)0);
	new = ft_lstnew(parser->wop);
	if (!new)
		return (parser->kill = 1, (void)0);
	ft_lstadd_back(&(parser->output), new);
	//ft_const_printer(parser);
	ft_reset_flags(parser);
	parser->state = NEW_STRING;
	(parser->format)++;
}
