/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:53:31 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 10:40:41 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

# define MAXBUF 16

typedef struct s_flags
{
	bool				prefix;
	char				sign_char;
	int					capitals;
}						t_flags;

void					print_c(va_list *argp);
void					print_hex(char c, va_list *argp, t_flags f);
void					print_pointer(va_list *argp, t_flags f);
void					print_diu(char c, va_list *argp, t_flags f);
void					print_string(va_list *argp);
void					_ftprintf(const char *fmt, va_list *argp, t_flags f);
void					ft_putchar(char c);
void					ft_putnbr_base(unsigned long u, int base, t_flags *f);
void					print_signed(int n, t_flags *f);
void					init(t_flags *f);

int						ft_printf(const char *fmt, ...);
int						g_cnt;

#endif
