/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:53:33 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 19:49:40 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define MAXBUF 9

typedef struct s_flags
{
	bool		left_justify;
	bool		sharp;
	bool		prefix;
	char		specifier;
	char		padding;
	char		plusorspace;
	char		sign_char;
	int			precision;
	int			width;
	int			capitals;
}				t_flags;

const char		*get_precision(const char *fmt, va_list *argp,
					t_flags *f);
const char		*get_width(const char *fmt, va_list *argp, t_flags *f);
char			*get_prefix(t_flags f, int base, unsigned long u);
const char		*get_flags(const char *fmt, t_flags *f);

void			print_string_helper(long n, char	*p, t_flags f);
void			ft_putnbr_base(unsigned long u, int base, t_flags *f);
void			_ftprintf(const char *fmt, va_list *argp, t_flags f);
void			print_signed(int n, va_list *argp, t_flags *f);
void			print_diu(char c, va_list *argp, t_flags *f);
void			flags_width_precision_helper(t_flags *f, char	*prefix);
void			print_hex(char c, va_list *argp, t_flags f);
void			print_pointer(va_list *argp, t_flags f);
void			print_string(va_list *argp, t_flags f);
void			print_c(va_list *argp, t_flags f);
void			ft_putchar(int c);
void			init(t_flags *f);

int				ft_strlen(const char	*s);
int				ctod(char c);
int				ft_isdigit(int d);
int				ft_printf(const char *fmt, ...);

int				g_cnt;

#endif
