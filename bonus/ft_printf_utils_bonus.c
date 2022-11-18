/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:34:32 by asioud            #+#    #+#             */
/*   Updated: 2022/11/18 10:03:48 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	flags_width_precision_helper(t_flags *f, char	*prefix)
{
	if (f->precision > 0)
	{
		if (f->sign_char)
			ft_putchar(f->sign_char);
		f->width += f->precision;
		while (--(f->width) >= 0)
			ft_putchar('0');
		return ;
	}
	if (f->sign_char)
		f->width--;
	if (*prefix)
		f->width -= ft_strlen((const char *)prefix);
	if (f->padding == ' ' && !f->left_justify)
		while (--(f->width) >= 0)
			ft_putchar(' ');
	if (f->sign_char)
		ft_putchar(f->sign_char);
	if (*prefix)
		while (*prefix)
			ft_putchar(*prefix++);
	if (f->padding == '0')
		while (--(f->width) >= 0)
			ft_putchar('0');
}

const char	*get_flags(const char *fmt, t_flags *f)
{
	while (true)
	{
		if (*fmt == '#')
			f->prefix = true;
		else if (*fmt == '-')
			f->left_justify = true;
		else if (*fmt == '+')
			f->plusorspace = '+';
		else if (*fmt == ' ')
		{
			if (f->plusorspace == 0)
				f->plusorspace = ' ';
		}
		else
			break ;
		fmt++;
	}
	if (*fmt == '0')
	{
		f->padding = '0';
		fmt++;
	}
	return (fmt);
}

const char	*get_width(const char *fmt, va_list *argp, t_flags *f)
{
	if (ft_isdigit(*fmt))
	{
		while (ft_isdigit(*fmt))
		{
			f->width = 10 * f->width + ctod(*fmt);
			fmt++;
		}
	}
	else if (*fmt == '*')
	{
		f->width = va_arg(*argp, int);
		fmt++;
		if (f->width < 0)
		{
			f->left_justify = !f->left_justify;
			f->width = -f->width;
		}
	}
	return (fmt);
}

const char	*get_precision(const char *fmt, va_list *argp, t_flags *f)
{
	if (*fmt == '.')
	{
		fmt++;
		f->precision = 0;
		if (ft_isdigit(*fmt))
		{
			while (ft_isdigit(*fmt))
			{
				f->precision = 10 * f->precision + ctod(*fmt);
				fmt++;
			}
		}
		else if (*fmt == '*')
		{
			f->precision = va_arg(*argp, int);
			fmt++;
		}
	}
	return (fmt);
}

char	*get_prefix(t_flags f, int base, unsigned long u)
{
	char	*prefix;

	prefix = "";
	if (f.prefix)
	{
		if (f.sharp == true && u != 0)
		{
			if (base == 16 && f.capitals)
				prefix = "0X";
			else
				prefix = "0x";
		}
		else if (f.sharp == false)
		{
			if (base == 16 && f.capitals)
				prefix = "0X";
			else
				prefix = "0x";
		}
	}
	return (prefix);
}
