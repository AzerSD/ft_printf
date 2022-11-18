/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:59:05 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 10:40:22 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(va_list *argp)
{
	char	*p;

	p = va_arg(*argp, char *);
	if (p == NULL)
		p = "(null)";
	while (*p)
		ft_putchar(*p++);
}

void	print_diu(char c, va_list *argp, t_flags f)
{
	int				n_signed;
	unsigned int	n_unsigned;

	if (c == 'u')
	{
		n_unsigned = va_arg(*argp, unsigned long);
		ft_putnbr_base(n_unsigned, 10, &f);
	}
	else
	{
		n_signed = va_arg(*argp, int);
		print_signed(n_signed, &f);
	}
}

void	print_pointer(va_list *argp, t_flags f)
{
	unsigned long	n_unsigned;

	f.prefix = true;
	n_unsigned = va_arg(*argp, unsigned long);
	ft_putnbr_base(n_unsigned, 16, &f);
}

void	print_hex(char c, va_list *argp, t_flags f)
{
	unsigned long	n_unsigned;

	if (c == 'X')
		f.capitals = 16;
	n_unsigned = va_arg(*argp, unsigned int);
	ft_putnbr_base(n_unsigned, 16, &f);
}

void	print_c(va_list *argp)
{
	int	c;

	c = va_arg(*argp, int);
	ft_putchar(c);
}
