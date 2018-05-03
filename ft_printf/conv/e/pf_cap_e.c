/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:44:53 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/04 00:40:41 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/17 19:20:47 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
static int	pf_create(t_flags *flags, t_var *var, long double d, int count)
{
	pf_ftoa(d, flags, var);
	if (flags->precision == 0 && flags->hashtag)
		var->bufindex--;
	pf_round(&var->buf[var->bufindex - 1], flags, var);
=======
void		pf_eround(char *str, t_flags *flags, t_var *var)
{
	if (*str >= '5')
	{
		while (*(--str) == '9')
		{
			*str = 0;
			var->bufindex--;
		}
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
		var->bufindex--;
	}
	else if (*(--str) == '.' && !flags->hashtag)
	{
		*str = 0;
		var->bufindex--;
	}
}

static int	pf_create(t_flags *flags, t_var *var, double d, int count)
{
	pf_ftoa(d, flags, var);
	pf_eround(&var->buf[var->bufindex - 1], flags, var);
>>>>>>> refs/remotes/origin/master
	addchar('E', var);
	if (count < 0)
	{
		addchar('-', var);
		count *= -1;
	}
	else
		addchar('+', var);
	if (count < 10)
		addchar('0', var);
<<<<<<< HEAD
	addnstr(ft_itoa(count), 1, var);
	return (0);
}

static int	initialise(t_flags *flags, t_var *var, long double d)
{
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = 1;
	flags->precision += 7 * (!flags->isp);
	flags->fwidth -= flags->precision + 5 +
	(flags->precision != 0 || flags->hashtag)
=======
	addstr(ft_itoa(count), var);
	return (0);
}

static int	initialise(t_flags *flags, t_var *var, double d)
{
	if (!(d == d))
		return (pf_nanc(flags, var));
	if (d == INFINITY || d == -INFINITY || d == 9221120237041090560)
		return (pf_infinitec(d, flags, var));
	flags->len = 1;
	flags->precision += 7 * (!flags->isp);
	flags->fwidth -= flags->len + flags->precision + 5
>>>>>>> refs/remotes/origin/master
	+ (d < 0 || flags->space || flags->plus);
	flags->fwidth *= (flags->fwidth > 0);
	return (0);
}

int			pf_cap_e(t_flags *flags, t_var *var, va_list ap)
{
<<<<<<< HEAD
	int			count;
	long double	d;

	if (flags->bigl)
		d = va_arg(ap, long double);
=======
	int		count;
	double	d;

	if (flags->bigl)
		return (pf_le(flags, var, ap));
>>>>>>> refs/remotes/origin/master
	else
		d = va_arg(ap, double);
	count = pf_tosc(&d);
	initialise(flags, var, d);
<<<<<<< HEAD
	return (pf_spe_cap_e(flags, var, d, count));
}

int			pf_spe_cap_e(t_flags *flags, t_var *var, long double d, int count)
{
	if (!flags->minus)
	{
		if (flags->zero)
		{
			pf_addminp(flags, var, d);
			flags->fwidth = addmchar('0', var, flags->fwidth);
		}
		else
		{
			flags->fwidth = addmchar(' ', var, flags->fwidth);
			pf_addminp(flags, var, d);
		}
=======
	pf_spe_cap_e(flags, var, d, count);
	return (1);
}

int			pf_spe_cap_e(t_flags *flags, t_var *var, double d, int count)
{
	char		width;

	width = ' ' + 16 * flags->zero;
	if (d < 0)
		addchar('-', var);
	else if (flags->plus || flags->space)
		addchar(flags->plus ? '+' : ' ', var);
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
>>>>>>> refs/remotes/origin/master
		pf_create(flags, var, d, count);
	}
	else
	{
<<<<<<< HEAD
		pf_addminp(flags, var, d);
		pf_create(flags, var, d, count);
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
=======
		pf_create(flags, var, d, count);
		flags->fwidth = addmchar(width, var, flags->fwidth);
>>>>>>> refs/remotes/origin/master
	}
	return (0);
}
