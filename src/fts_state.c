/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:33 by becanals          #+#    #+#             */
/*   Updated: 2025/11/18 21:13:55 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_format_conver(t_parser *parser)
{
	t_list	*new;

	if (!ft_memchr("cspdiuxX", parser->format[0], 8))
	{
		parser->wop = NULL;
		parser->state = FORCED_STRING;
		return ;
	}
	parser->cvt_fts_array[ft_memchr_pos("cspdiuxX%", parser->format[0], 9)]
		(parser);
	new = ft_lstnew(parser->wop);
	if (!new)
		return (parser->kill = 1, (void)0);
	ft_lstadd_back(&(parser->output), new);
	if (parser->wop[0] == 0 && parser->format[0] == 'c')
	{
		new = ft_lstlast(parser->output);
		new->c_flag = 1;
	}
	parser->wop = NULL;
	parser->state = NEW_STRING;
	(parser->format)++;
}

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
		parser->state = FORMAT_CONVER;
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
