/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:35:09 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 19:46:27 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	_ftprintf(const char *fmt, va_list *argp, t_flags f)
{
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			ft_putchar(*fmt++);
			continue ;
		}
		if (*++fmt == 'c')
			print_c(argp);
		else if (*fmt == 's')
			print_string(argp);
		else if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u')
			print_diu(*fmt, argp, f);
		else if (*fmt == 'p')
			print_pointer(argp, f);
		else if (*fmt == 'x' || *fmt == 'X')
			print_hex(*fmt, argp, f);
		else
			ft_putchar(*fmt);
		fmt++;
	}
}
