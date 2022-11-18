/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:39:58 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 10:04:02 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_base(unsigned long u, int base, t_flags *f)
{
	char	buf[MAXBUF];
	char	*p;
	char	*digits;
	char	*prefix;

	p = &buf[MAXBUF - 1];
	digits = "0123456789abcdef0123456789ABCDEF";
	prefix = get_prefix(*f, base, u);
	if (u == 0)
		*p-- = digits[(u % base) + f->capitals];
	while (u != 0)
	{
		*p-- = digits[(u % base) + f->capitals];
		u /= base;
	}
	f->width -= (&buf[MAXBUF - 1] - p);
	flags_width_precision_helper(f, prefix);
	while (++p != &buf[MAXBUF])
		ft_putchar(*p);
	if (f->left_justify)
		while (--f->width >= 0)
			ft_putchar(' ');
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
	g_cnt++;
}

int	ft_isdigit(int d)
{
	return ((d >= '0') && (d <= '9'));
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ctod(char c)
{
	return ((c) - '0');
}
