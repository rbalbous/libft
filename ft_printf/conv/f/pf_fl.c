/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:30:50 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/04 00:35:55 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/17 19:03:35 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
int		pf_infinite(long double d, t_flags *flags, t_var *var)
{
	flags->fwidth -= 3 + (flags->space || flags->plus || d < 0);
	flags->fwidth *= (flags->fwidth > 0);
	if (!flags->minus)
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
=======
int		pf_linfinite(long double d, t_flags *flags, t_var *var)
{
	int		width;

	flags->precision += 7 * (!flags->isp);
	flags->fwidth -= 3 + (flags->space || flags->plus || d < 0);
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
>>>>>>> refs/remotes/origin/master
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
<<<<<<< HEAD
		flags->fwidth = addmchar(' ', var, flags->fwidth);
=======
		flags->fwidth = addmchar(width, var, flags->fwidth);
>>>>>>> refs/remotes/origin/master
	}
	return (0);
}

<<<<<<< HEAD
void	pf_addminp(t_flags *flags, t_var *var, long double d)
{
	if (d < 0)
		addchar('-', var);
	else if ((flags->plus || flags->space))
		addchar(flags->plus ? '+' : ' ', var);
}

int		pf_fcreate(t_flags *flags, t_var *var, long double d, char width)
{
	if (!flags->minus)
	{
		if (flags->zero)
		{
			pf_addminp(flags, var, d);
			flags->fwidth = addmchar(width, var, flags->fwidth);
		}
		else
		{
			flags->fwidth = addmchar(width, var, flags->fwidth);
			pf_addminp(flags, var, d);
		}
	}
	if (flags->minus)
		pf_addminp(flags, var, d);
	pf_ftoa(d, flags, var);
	if (flags->precision == 0 && flags->hashtag)
		var->bufindex--;
	pf_round(&var->buf[var->bufindex - 1], flags, var);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
=======
int		pf_fl(t_flags *flags, t_var *var, va_list ap)
{
	long double		d;

	d = va_arg(ap, long double);
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
	flags->precision += 7 * (!flags->isp);
	if (d == 0)
	{
		addstr("0.", var);
		while (flags->precision-- > 0)
			addchar('0', var);
		return (0);
	}
	return (pf_spe_f(flags, var, d));
}

int		pf_spe_fl(t_flags *flags, t_var *var, long double d)
{
	char		width;
	int			apo;

	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY || d == 9221120237041090560)
		return (pf_linfinite(d, flags, var));
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flags->fwidth -= (flags->hashtag && flags->precision == 0);
	flags->fwidth *= (flags->fwidth > 0);
	flags->fwidth -= flags->precision + flags->len + (flags->precision != 0)
	+ (flags->space || flags->plus) + apo;
	width = ' ' + 16 * flags->zero;
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
>>>>>>> refs/remotes/origin/master
	return (0);
}
