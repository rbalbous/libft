/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:07:23 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/04 00:44:07 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/17 19:03:35 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
int			pf_around(char *str, char *base, t_flags *flags, long double d)
{
	if (*str >= base[9 - 1 * (flags->precision != -1)])
	{
		while (*(--str) == base[15])
			flags->len--;
		if (*str != '.')
		{
			if (*str == '9')
				*str += 40;
			else
				*str += 1;
		}
		else
		{
			if (*(--str) == '9')
				*str += 40;
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

int			pf_toa(long double *d, t_flags *flags)
=======
int			pf_toa(double *d)
>>>>>>> refs/remotes/origin/master
{
	int		count;
	int		sign;

	count = 0;
	sign = 1;
<<<<<<< HEAD
	if (flags->bigl)
		return (pf_tola(d));
=======
>>>>>>> refs/remotes/origin/master
	if ((intmax_t)(*d) == 0 && *d != 0)
	{
		while ((intmax_t)(*d) == 0)
		{
			*d = *d * 2;
			count++;
			sign = -1;
		}
	}
	while ((1 < (intmax_t)(*d) || -1 > (intmax_t)(*d)) && *d != 0)
	{
		*d /= 2;
		count++;
	}
	return (count * sign);
}

<<<<<<< HEAD
int			pf_acreate(t_var *var, t_flags *flags, int count, int len_count)
{
	int		start;

	start = var->bufindex - 2 - flags->len;
=======
static int	pf_create(t_flags *flags, t_var *var, double d, int count)
{
	int		start;

	start = var->bufindex;
	addstr("0x", var);
	if ((pf_ftoa_hexa(d, flags, var)) == -1)
		return (-1);
>>>>>>> refs/remotes/origin/master
	addchar('p', var);
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
		return (pf_azero(flags, var, d));
=======
	addstr(ft_itoa(count), var);
	return (0);
}

static char	initialise(t_flags *flags, t_var *var, double d)
{
>>>>>>> refs/remotes/origin/master
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = 1;
<<<<<<< HEAD
	flags->precision += 15 * (!flags->isp) - 1 * (!flags->bigl);
	return (1);
=======
	flags->precision += 15 * (!flags->isp) - 1;
	flags->fwidth -= 1 + flags->precision + 5
	+ (d < 0 || flags->space || flags->plus);
	flags->fwidth *= (flags->fwidth > 0);
	return (' ' + 16 * flags->zero);
>>>>>>> refs/remotes/origin/master
}

int			pf_a(t_flags *flags, t_var *var, va_list ap)
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
	pf_around(num + flags->len, "0123456789abcdef", flags, d);
	len_count = pf_intlen(count, 10) - (count < 0);
	pf_makea(flags, var, d, len_count);
	addnstr(num, flags->len, var);
	pf_acreate(var, flags, count, len_count);
	if (flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	free(num);
=======
	double		d;
	int			count;
	char		width;

	if (flags->bigl)
		return (pf_la(flags, var, ap));
	d = va_arg(ap, double);
	width = initialise(flags, var, d);
	count = pf_toa(&d);
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
