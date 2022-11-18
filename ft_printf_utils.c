/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:34:32 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 10:39:58 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_cnt++;
}

void	init(t_flags *f)
{
	f->prefix = false;
	f->sign_char = 0;
	f->capitals = 0;
}

void	ft_putnbr_base(unsigned long u, int base, t_flags *f)
{
	char	buf[MAXBUF];
	char	*p;
	char	*digits;
	char	*prefix;

	p = &buf[MAXBUF - 1];
	digits = "0123456789abcdef0123456789ABCDEF";
	prefix = 0;
	if (f->prefix)
		if (base == 16)
			prefix = "0x";
	if (u == 0)
		*p-- = digits[(u % base) + f->capitals];
	while (u != 0)
	{
		*p-- = digits[(u % base) + f->capitals];
		u /= base;
	}
	if (f->sign_char)
		ft_putchar(f->sign_char);
	if (f->prefix)
		while (*prefix)
			ft_putchar(*prefix++);
	while (++p != &buf[MAXBUF])
		ft_putchar(*p);
}

void	print_signed(int n, t_flags *f)
{
	unsigned int	u;

	u = n;
	if (n < 0)
	{
		u = -n;
		f->sign_char = '-';
	}
	ft_putnbr_base(u, 10, f);
}
