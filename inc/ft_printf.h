/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:12:43 by becanals          #+#    #+#             */
/*   Updated: 2025/10/22 19:01:49 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

enum e_state
{
	FINISH = 0,
	NEW_STRING,
	FORCED_STRING,
	FORMAT_FLAG,
	FORMAT_F_LEN,
	FORMAT_PRECISION,
	FORMAT_P_LEN,
	FORMAT_CONVER
};

enum e_conversion
{
	CHAR = 0,
	STRING,
	POINT,
	DEC,
	INT,
	UNSIGN,
	HEX_L,
	HEX_U,
	PERCENT,
};

typedef struct s_parser
{
	const char		*format;
	va_list			*args;
	t_list			*output;
	enum e_state	state;
	void			(*(*stt_fts_array))(struct s_parser *);
	void			(*(*cvt_fts_array))(struct s_parser *);
	char			flag_converter;
	char			flag_hash;
	char			flag_spc_plus;
	size_t			flag_len;
	char			precision;
	size_t			prec_len;
}				t_parser;

int			ft_printf(const char *format, ...);
t_parser	*parser_constr(const char *format, va_list *args);
int			clean_up(t_parser *parser, va_list *args);
void		ft_new_string(t_parser *parser);
void		ft_forced_string(t_parser *parser);
void		ft_format_flag(t_parser *parser);
void		ft_format_f_len(t_parser *parser);
void		ft_format_precision(t_parser *parser);
void		ft_format_p_len(t_parser *parser);
void		ft_format_conver(t_parser *parser);
void		ft_convert_c(t_parser *parser);
void		ft_convert_s(t_parser *parser);
void		ft_convert_p(t_parser *parser);
void		ft_convert_d(t_parser *parser);
void		ft_convert_i(t_parser *parser);
void		ft_convert_u(t_parser *parser);
void		ft_convert_xl(t_parser *parser);
void		ft_convert_xu(t_parser *parser);
void		ft_convert_percent(t_parser *parser);

#endif
