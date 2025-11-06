/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:43:25 by becanals          #+#    #+#             */
/*   Updated: 2025/11/02 17:17:47 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	my_free(void *del)
{
	if (!del)
		return ;
	free(del);
}

static void	ft_clean_up(t_parser *parser)
{
	if (parser)
	{
		if (parser->args)
			va_end(*(parser->args));
		if (parser->output)
			ft_lstclear(&(parser->output), &my_free);
		if (parser->stt_fts_array)
			free(parser->stt_fts_array);
		if (parser->cvt_fts_array)
			free(parser->cvt_fts_array);
		if (parser->wop)
			free(parser->wop);
		ft_memset(parser, 0, sizeof(t_parser));
		free(parser);
	}
}

void	debuger(t_parser *parser)
{
	ft_putstr_fd("====>>> now at: ", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
	(parser->stt_fts_array)[parser->state](parser);
}

void	ft_const_printer(t_parser *parser)
{
	char *str;

	ft_putstr_fd("flag conv: ", 1);
	ft_putchar_fd(parser->flag_converter, 1);
	ft_putstr_fd("\nflag hash: ", 1);
	ft_putchar_fd(parser->flag_hash + '0', 1);
	ft_putstr_fd("\nflag spc_pls: ", 1);
	ft_putchar_fd(parser->flag_spc_pls + '0', 1);
	ft_putstr_fd("\nflag zer_min: ", 1);
	ft_putchar_fd(parser->flag_zer_min + '0', 1);
	ft_putstr_fd("\nflag len: ", 1);
	str = ft_itoa(parser->flag_len);
	ft_putstr_fd(str, 1);
	free(str);
	ft_putstr_fd("\nprecision: ", 1);
	ft_putchar_fd(parser->precision + '0', 1);
	ft_putstr_fd("\nprec len: ", 1);
	str = ft_itoa(parser->prec_len);
	ft_putstr_fd(str, 1);
	free(str);
}

int	ft_printf(const char *format, ...)
{
	t_parser	*parser;
	va_list		args;

	va_start(args, format);
	parser = parser_constr(format, &args);
	if (!parser || parser->kill)
		return (va_end(args), -1);
	while (parser->state && !(parser->kill))
		(parser->stt_fts_array)[parser->state](parser);
	if (parser->kill)
		return (ft_clean_up(parser), -1);
	ft_putlst(parser->output);
	ft_clean_up(parser);
	return (1);
}
