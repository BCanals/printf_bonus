/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:43:25 by becanals          #+#    #+#             */
/*   Updated: 2025/11/12 18:08:36 by becanals         ###   ########.fr       */
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

static int	ft_put_and_getrtrn(t_parser *parser)
{
	int		rtrn;
	t_list	*list;

	rtrn = 0;
	list = parser->output;
	while (list)
	{
		ft_putstr_fd(list->content, 1);
		rtrn += ft_strlen(list->content);
		list = list->next;
	}
	rtrn += parser->add_return;
	return (rtrn);
}

int	ft_printf(const char *format, ...)
{
	t_parser	*parser;
	va_list		args;
	int			rtrn;

	va_start(args, format);
	parser = parser_constr(format, &args);
	if (!parser || parser->kill)
		return (va_end(args), -1);
	while (parser->state && !(parser->kill))
		(parser->stt_fts_array)[parser->state](parser);
	if (parser->kill)
		return (ft_clean_up(parser), -1);
	rtrn = ft_put_and_getrtrn(parser);
	ft_clean_up(parser);
	return (rtrn);
}
