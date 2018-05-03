/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_g.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:42:14 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/22 15:02:19 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/19 22:13:34 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
int		pf_gzer(t_flags *flags, t_var *var, long double d)
{
	long double	tmp;
	int			count;
=======
int		pf_ground(char *str, t_var *var)
{
	while (*str == '0')
	{
		var->bufindex--;
		str--;
	}
	if (*str == '.')
		var->bufindex--;
	return (0);
}

int		pf_gzer(t_flags *flags, t_var *var, double d)
{
	double	tmp;
	int		count;
>>>>>>> refs/remotes/origin/master

	tmp = d;
	count = 0;
	while ((intmax_t)tmp == 0 && d != 0)
	{
		tmp *= 10;
<<<<<<< HEAD
		count--;
	}
	if (count > flags->precision || count < -4)
		return (pf_ge(flags, var, tmp, count));
	else
		return (pf_gf(flags, var, d));
	return (0);
}

int		pf_gpos(t_flags *flags, t_var *var, long double d)
{
	int			count;
	int			leng;

	leng = pf_intlen((intmax_t)d, 10) - (d < 0);
	if (leng > 6 || (flags->precision + 1 < leng))
	{
		count = pf_tosc(&d);
		pf_ge(flags, var, d, count);
	}
	else
		pf_gf(flags, var, d);
	return (1);
}

int		pf_cap_g(t_flags *flags, t_var *var, va_list ap)
{
	flags->capx = 1;
	return (pf_g(flags, var, ap));
}

int		pf_g(t_flags *flags, t_var *var, va_list ap)
{
	long double	d;

	if (flags->bigl)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->precision += (!flags->isp) * 7 - 1;
	flags->precision *= (flags->precision > 0);
=======
		count++;
	}
	if (count > 4)
	{
		if (flags->bigl)
			return (pf_spe_le(flags, var, d, -count));
		else
			return (pf_spe_e(flags, var, tmp, -count));
	}
	else
	{
		flags->precision += count + (flags->precision == -1);
		if (flags->bigl)
			return (pf_spe_fl(flags, var, d));
		else
			return (pf_spe_f(flags, var, d));
	}
}

int		pf_gpos(t_flags *flags, t_var *var, double d)
{
	int			count;

	count = 0;
	if (flags->len > flags->precision + 1)
	{
		flags->len = 1;
		count = pf_tosc(&d);
		if (flags->bigl)
			pf_spe_le(flags, var, d, count);
		else
			pf_spe_e(flags, var, d, count);
	}
	else
	{
		flags->precision -= flags->len - 1;
		flags->precision *= (flags->precision > 0);
		if (flags->bigl)
			pf_spe_fl(flags, var, d);
		else
			pf_spe_f(flags, var, d);
	}
	return (1);
}

int		pf_g(t_flags *flags, t_var *var, va_list ap)
{
	double		d;

	d = va_arg(ap, double);
	flags->g = 1;
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY || d == 9221120237041090560)
		return (pf_infinite(d, flags, var));
	flags->precision += (!flags->isp) * 7 - 1;
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
>>>>>>> refs/remotes/origin/master
	if ((intmax_t)d == 0)
		pf_gzer(flags, var, d);
	else
		pf_gpos(flags, var, d);
	return (0);
}
