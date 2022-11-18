/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:59:00 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 10:44:11 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_string(va_list *argp, t_flags f)
{
	char	*p;
	long	n;

	if (f.precision == -1)
		f.precision = 0x7fffffff;
	p = va_arg(*argp, char *);
	if (p == (char *)0)
		p = "(null)";
	n = 0;
	print_string_helper(n, p, f);
	while (*p)
	{
		if (++n > f.precision || (f.width > 0 && n > f.width + 1))
			break ;
		ft_putchar(*p++);
	}
	if (n < f.width && f.left_justify)
		while (n++ < f.width)
			ft_putchar(' ');
}

void	print_diu(char c, va_list *argp, t_flags *f)
{
	int				n_signed;
	unsigned int	n_unsigned;
	unsigned int	u;

	if (c == 'u')
	{
		n_unsigned = va_arg(*argp, unsigned int);
		ft_putnbr_base(n_unsigned, 10, f);
	}
	else
	{
		n_signed = va_arg(*argp, int);
		u = n_signed;
		if (n_signed >= 0)
			f->sign_char = f->plusorspace;
		else
		{
			u = -n_signed;
			f->sign_char = '-';
		}
		ft_putnbr_base(u, 10, f);
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

	f.sharp = true;
	if (c == 'X')
		f.capitals = 16;
	n_unsigned = va_arg(*argp, unsigned int);
	ft_putnbr_base(n_unsigned, 16, &f);
}

void	print_c(va_list *argp, t_flags f)
{
	char	c;
	int		n;

	c = va_arg(*argp, int);
	if (f.width > 0 && !f.left_justify)
	{
		n = 1;
		while (n < f.width)
		{
			ft_putchar(' ');
			n++;
		}
	}
	n = 1;
	ft_putchar(c);
	if (n < f.width && f.left_justify)
	{
		while (n < f.width)
		{
			ft_putchar(' ');
			n++;
		}
	}
}
