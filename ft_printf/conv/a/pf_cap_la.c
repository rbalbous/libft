/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_la.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:33:44 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/04 00:04:28 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/17 19:03:35 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
int			pf_makecapa(t_flags *flags, t_var *var, long double d, int lc)
{
	flags->fwidth -= (flags->len + lc + (flags->space || flags->plus || d < 0) +
	4 + (flags->precision == -1 && flags->hashtag)) * !(flags->bigl && d == 0);
	flags->fwidth *= (flags->fwidth > 0);
	if (flags->precision == -1 && flags->hashtag)
		flags->len++;
	if (flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addnstr("0X", 2, var);
	}
	if (!flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	if (!flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addnstr("0X", 2, var);
	}
	return (0);
}

int			pf_capazero(t_flags *flags, t_var *var, long double d)
{
	char	width;

	flags->fwidth -= 6 + (flags->space || flags->plus || d < 0)
	+ (flags->precision > 0 || flags->hashtag) + flags->precision * flags->isp;
	pf_makecapa(flags, var, d, 0);
	width = ' ' + 16 * flags->zero;
	addchar('0', var);
	if (flags->precision > 0 || flags->hashtag)
		addchar('.', var);
	while (flags->precision-- > 0)
		addchar('0', var);
	addnstr("P+0", 3, var);
=======
static int	pf_create(t_flags *flags, t_var *var, long double d, int count)
{
	int		start;

	start = var->bufindex;
	addstr("0X", var);
	d = (d < 0) ? -d : d;
	pf_uitoa_hexa(d, flags, var);
	if ((pf_fltoa_hexa(d, flags, var)) == -1)
		return (-1);
	addchar('P', var);
	if (count < 0)
	{
		addchar('-', var);
		count *= -1;
	}
	else
		addchar('+', var);
	addstr(ft_itoa(count), var);
	return (0);
}

static int	initialise(t_flags *flags, t_var *var, long double d)
{
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_linfinite(d, flags, var));
	flags->len = 1;
	flags->capx = 1;
	flags->precision += 17 * (!flags->isp) - 1;
	flags->fwidth -= 1 + flags->precision + 5
	+ (d < 0 || flags->space || flags->plus);
	flags->fwidth *= (flags->fwidth > 0);
	return (0);
}

int			pf_cap_la(t_flags *flags, t_var *var, va_list ap)
{
	long double	d;
	int			count;
	char		width;

	d = va_arg(ap, long double);
	count = pf_tola(&d);
	initialise(flags, var, d);
	width = ' ' + 16 * flags->zero;
	if (d < 0)
		addchar('-', var);
	else if (flags->plus || flags->space)
		addchar(flags->plus ? '+' : ' ', var);
	if (!flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	if ((pf_create(flags, var, d, count)) == -1)
		return (-1);
>>>>>>> refs/remotes/origin/master
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}
