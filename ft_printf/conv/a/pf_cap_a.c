/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:33:44 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/04 00:46:43 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/17 19:03:35 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
int			pf_caparound(char *str, char *base, t_flags *flags, long double d)
{
	if (*str >= base[9 - 1 * (flags->precision != -1)])
	{
		while (*(--str) == base[15])
			flags->len--;
		if (*str != '.')
		{
			if (*str == '9')
				*str += 8;
			else
				*str += 1;
		}
		else
		{
			if (*(--str) == '9')
				*str += 8;
			else
				*str += 1;
			if (!(flags->hashtag && flags->bigl))
				flags->len--;
		}
	}
	else if (flags->len == 2 && (!((intmax_t)d == 0
	&& flags->hashtag && flags->precision != -1)))
		flags->len--;
	return (0);
}

int			pf_capacreate(t_var *var, t_flags *flags, int count, int len_count)
{
	int		start;

	start = var->bufindex - 2 - flags->len;
=======
static int	pf_create(t_flags *flags, t_var *var, double d, int count)
{
	int		start;

	start = var->bufindex;
	addstr("0X", var);
	if ((pf_ftoa_hexa(d, flags, var)) == -1)
		return (-1);
>>>>>>> refs/remotes/origin/master
	addchar('P', var);
	if (count < 0)
	{
		addchar('-', var);
		count *= -1;
	}
	else
		addchar('+', var);
<<<<<<< HEAD
	addnstr(ft_itoa(count), len_count, var);
	return (0);
}

static int	initialise(t_flags *flags, t_var *var, long double d)
{
	if (d == 0 && flags->bigl)
		return (pf_capazero(flags, var, d));
	if (!(d == d))
		return (pf_nanc(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinitec(d, flags, var));
	flags->len = 1;
	flags->precision += 15 * (!flags->isp) - 1 * (!flags->bigl);
	flags->capx = 1;
	return (1);
=======
	addstr(ft_itoa(count), var);
	return (0);
}

static int	initialise(t_flags *flags, t_var *var, double d)
{
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = 1;
	flags->capx = 1;
	flags->precision += 15 * (!flags->isp) - 1;
	flags->fwidth -= 1 + flags->precision + 5
	+ (d < 0 || flags->space || flags->plus);
	flags->fwidth *= (flags->fwidth > 0);
	return (0);
>>>>>>> refs/remotes/origin/master
}

int			pf_cap_a(t_flags *flags, t_var *var, va_list ap)
{
<<<<<<< HEAD
	long double	d;
	int			count;
	char		*num;
	int			len_count;

	if (flags->bigl)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	if (initialise(flags, var, d) == 0)
		return (0);
	count = pf_toa(&d, flags);
	if ((num = (pf_ftoa_hexa(d, flags))) == NULL)
		return (-1);
	pf_caparound(num + flags->len, "0123456789ABCDEF", flags, d);
	len_count = pf_intlen(count, 10) - (count < 0);
	pf_makecapa(flags, var, d, len_count);
	addnstr(num, flags->len, var);
	pf_capacreate(var, flags, count, len_count);
	if (flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	free(num);
=======
	double		d;
	int			count;
	char		width;

	if (flags->bigl)
		return (pf_cap_la(flags, var, ap));
	d = va_arg(ap, double);
	initialise(flags, var, d);
	count = pf_toa(&d);
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
>>>>>>> refs/remotes/origin/master
	return (0);
}
