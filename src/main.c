/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:43:25 by becanals          #+#    #+#             */
/*   Updated: 2025/10/27 18:15:43 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	my_free(void *del)
{
	if (!del)
		return ;
	free(del);
}

void	clean_up(t_parser *parser, va_list *args)
{
	va_end(*args);
	if (parser)
	{
		if (parser->output)
			ft_lstclear(&(parser->output), &my_free);
		if (parser->stt_fts_array)
			free(parser->stt_fts_array);
		if (parser->cvt_fts_array)
			free(parser->cvt_fts_array);
		if (parser->wop)
			free(parser->wop);
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
/*
void	printer(void *parser)
{
	t_list	*to_print;

	to_print = parser->output;
	while (to_print)
	{
		ft_putstr_fd(to_print->content, 1);
		to_print = to_print->next;
	}
}
*/
int	ft_printf(const char *format, ...)
{
	t_parser	*parser;
	va_list		args;

	va_start(args, format);
	parser = parser_constr(format, &args);
	if (!parser)
		return (clean_up(parser, &args), -1);
	ft_putstr_fd("++++++++++PARSING, START!+++++++++++\n", 1);
	while (parser && parser->state)
		debuger(parser);
	if (!parser)
		return (-1);
	//parser->stt_fts_array[parser->state] (parser);
	ft_putstr_fd("++++++++++PARSING FINISHED!+++++++++\n", 1);
	ft_putlst(parser->output);
	//ft_prinit(parser->output);
	clean_up(parser, &args);
	return (1);
}
