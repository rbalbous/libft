/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:30:50 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/04 00:30:41 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/19 23:45:00 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
int		pf_fzero(long double d, t_flags *flags, t_var *var)
{
	char	width;

	flags->fwidth -= (flags->hashtag) +
	(flags->space || flags->plus || (d < 0)) + flags->len;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
=======
int		pf_infinite(double d, t_flags *flags, t_var *var)
{
	int		width;

	flags->precision += 7 * (!flags->isp);
	flags->fwidth -= 3 + (flags->space || flags->plus || d < 0);
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("inf", 3, var);
	}
	else
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("inf", 3, var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
>>>>>>> refs/remotes/origin/master
	return (0);
}

int		pf_nan(t_flags *flags, t_var *var)
{
	char	width;

	flags->fwidth -= 3;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("nan", 3, var);
	}
	else
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("nan", 3, var);
	}
	return (0);
}

int		pf_round(char *str, t_flags *flags, t_var *var)
{
	if (*str >= '5')
	{
		while (*(--str) == '9')
			*str = '0';
		if (*str == '.')
		{
			if (*(str + 2) == 0 && !flags->hashtag)
			{
				*str = 0;
				var->bufindex--;
			}
			*(--str) += 1;
		}
		else
			*str += 1;
	}
	else if (*(--str) == '.' && !flags->hashtag)
<<<<<<< HEAD
		var->bufindex--;
	var->bufindex--;
=======
	{
		*str = 0;
		var->bufindex--;
	}
	var->bufindex--;
	if (flags->g)
		return (pf_ground(&var->buf[var->bufindex - 1], var));
>>>>>>> refs/remotes/origin/master
	return (0);
}

int		pf_f(t_flags *flags, t_var *var, va_list ap)
{
<<<<<<< HEAD
	long double	d;
	int			apo;
	char		width;

	if (flags->bigl)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	width = ' ' + 16 * flags->zero;
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
	if (flags->precision == 0)
		return (pf_fzero(d, flags, var));
	flags->precision += 7 * (!flags->isp);
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flags->fwidth -= flags->precision + flags->len
	+ (flags->space || flags->plus || d < 0) + apo + 1;
	flags->fwidth *= (flags->fwidth > 0);
=======
	double		d;

	if (flags->bigl)
		return (pf_cap_fl(flags, var, ap));
	else
		d = va_arg(ap, double);
	printf("%f\n", d);
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
	flags->precision += 7 * (!flags->isp);
	if (d == 0 && flags->precision > 0)
	{
		addstr("0.", var);
		while (flags->precision-- > 0)
			addchar('0', var);
		return (0);
	}
	return (pf_spe_f(flags, var, d));
}

int		pf_spe_f(t_flags *flags, t_var *var, double d)
{
	char		width;
	int			apo;

	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY || d == 9221120237041090560)
		return (pf_infinite(d, flags, var));
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flags->fwidth -= (flags->hashtag && flags->precision == 0);
	flags->fwidth *= (flags->fwidth > 0);
	flags->fwidth -= flags->precision * (!flags->g) + (flags->precision != 0)
	+ (flags->space || flags->plus) + apo + (!flags->g);
	width = ' ' + 16 * flags->zero;
>>>>>>> refs/remotes/origin/master
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
	return (0);
}
