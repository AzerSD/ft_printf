/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:35:09 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 11:19:00 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//  "% [flags] [width] [.precision] [width] specifier"
void	_ftprintf(const char *fmt, va_list *argp, t_flags f)
{
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			ft_putchar(*fmt++);
			continue ;
		}
		init(&f);
		fmt = get_flags(++fmt, &f);
		fmt = get_width(fmt, argp, &f);
		fmt = get_precision(fmt, argp, &f);
		if (*fmt == 'c')
			print_c(argp, f);
		else if (*fmt == 's')
			print_string(argp, f);
		else if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u')
			print_diu(*fmt, argp, &f);
		else if (*fmt == 'p')
			print_pointer(argp, f);
		else if (*fmt == 'x' || *fmt == 'X')
			print_hex(*fmt, argp, f);
		else if (*fmt == '%')
			ft_putchar(*fmt);
		fmt++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arguments;
	t_flags	f;

	init(&f);
	va_start(arguments, fmt);
	_ftprintf(fmt, &arguments, f);
	va_end(arguments);
	return (g_cnt);
}

void	init(t_flags *f)
{
	f->left_justify = false;
	f->prefix = false;
	f->sharp = false;
	f->width = 0;
	f->precision = -1;
	f->padding = ' ';
	f->plusorspace = 0;
	f->sign_char = 0;
	f->capitals = 0;
}

void	print_string_helper(long n, char	*p, t_flags f)
{
	char	*p2;

	if (f.width > 0 && !f.left_justify)
	{
		n = 0;
		p2 = p;
		while (*p++ && n < f.precision)
			n++;
		p = p2;
		while (n++ < f.width)
			ft_putchar(' ');
	}
}
