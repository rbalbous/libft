/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:44 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/12 15:50:41 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_isnull(t_flags *flags, t_var *var)
{
<<<<<<< HEAD
	char	width;

	width = ' ' + 16 * (flags->zero);
	if (flags->precision > 6 || !flags->isp)
		flags->fwidth -= 6;
	else
		flags->fwidth -= flags->precision;
	flags->fwidth *= (flags->fwidth > 0);
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		return (addnull(flags, var));
	}
	else
	{
		addnull(flags, var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
		return (0);
	}
}

int		pf_addzero(t_flags *flags, t_var *var)
{
	char	width;

	width = ' ' + 16 * (flags->zero);
	flags->fwidth -= flags->precision * (flags->precision > 0);
	flags->fwidth *= (flags->fwidth > 0);
	flags->fwidth = addmchar(width, var, flags->fwidth);
	return (addnull(flags, var));
=======
	if (!flags->isp)
		return (addnull(var));
	else
		return (pf_empty_s(flags, var));
>>>>>>> refs/remotes/origin/master
}

int		pf_s(t_flags *flags, t_var *var, va_list ap)
{
	char	*tmp;
<<<<<<< HEAD
=======
	char	width;
>>>>>>> refs/remotes/origin/master

	if (flags->conv == l)
		return (pf_cap_s(flags, var, ap));
	tmp = va_arg(ap, char*);
<<<<<<< HEAD
	if (flags->precision == 0)
		return (pf_addzero(flags, var));
	if (tmp == NULL)
		return (pf_isnull(flags, var));
	flags->len = ft_strlen(tmp);
=======
	if (tmp == NULL)
		return (pf_isnull(flags, var));
	flags->len = ft_strlen(tmp);
	width = ' ' + 16 * (flags->zero);
>>>>>>> refs/remotes/origin/master
	if (flags->precision >= 0 && flags->precision < flags->len)
		flags->len = flags->precision;
	flags->fwidth -= flags->len;
	flags->fwidth *= (flags->fwidth > 0);
	if (flags->minus == 0)
	{
<<<<<<< HEAD
		addmchar(' ' + 16 * (flags->zero), var, flags->fwidth);
=======
		flags->fwidth = addmchar(width, var, flags->fwidth);
>>>>>>> refs/remotes/origin/master
		addnstr(tmp, (size_t)flags->len, var);
	}
	else
	{
		addnstr(tmp, (size_t)flags->len, var);
<<<<<<< HEAD
		addmchar(' ' + 16 * (flags->zero), var, flags->fwidth);
=======
		flags->fwidth = addmchar(width, var, flags->fwidth);
>>>>>>> refs/remotes/origin/master
	}
	return (0);
}
