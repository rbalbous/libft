/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_la.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:33:44 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/17 19:03:35 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}
