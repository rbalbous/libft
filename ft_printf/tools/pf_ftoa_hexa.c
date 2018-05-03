/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:21:11 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/02/17 15:58:59 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/17 17:55:16 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countprec(t_flags *flags, char *str)
{
	int		i;

<<<<<<< HEAD
	i = 15 + flags->bigl;
	if (flags->isp)
	{
		flags->len = (flags->precision + 3 - (flags->bigl));
		return (flags->precision + 3 - (flags->bigl));
	}
	while (str[i] == '0')
	{
		i--;
	}
	i += 1 * (i != 0);
	if (i == 2)
		flags->precision = -1;
	flags->len = i;
	return (i);
}

char		*pf_ftoa_hexa(long double n, t_flags *flags)
=======
	i = 14 + flags->bigl;
	if (flags->isp)
		return (flags->precision + 2);
	while (str[i] == '0')
		i--;
	i += 1 * (i != 0);
	return (i);
}

int			pf_ftoa_hexa(double n, t_flags *flags, t_var *var)
{
	char			*str;
	int				i;
	static char		modu[16];
	int				flag;

	i = 1;
	if (!modu[0])
		pf_initoa(modu);
	addchar('1' - (n == 0), var);
	if (!(str = ft_memalloc(flags->precision + 2)))
		return (-1);
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[0] = flags->dpt * (flags->precision > 0);
	while (i < flags->precision + 2)
	{
		n = (n - (intmax_t)n) * 16 * (-2 * (n < 0) + 1);
		flag = flags->capx * (((intmax_t)n & 15) > 9 && i != 0);
		str[i] = modu[(intmax_t)n] - flag * 32;
		i++;
	}
	str[i] = 0;
	addnstr(str, countprec(flags, str), var);
	free(str);
	return (0);
}

int			pf_fltoa_hexa(long double n, t_flags *flags, t_var *var)
>>>>>>> refs/remotes/origin/master
{
	char			*str;
	int				i;
	static char		modu[16];
	int				flag;

<<<<<<< HEAD
	i = 2;
	if (!modu[0])
		pf_initoa(modu);
	if (!(str = ft_memalloc(flags->precision + 4
	+ (flags->precision == -1 * (!flags->bigl)))))
		return (NULL);
	str[0] = modu[(int)(n * (1 - 2 * (n < 0)))] -
	flags->capx * (int)((n * (1 - 2 * (n < 0)) > 10)) * 32;
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[1] = flags->dpt;
	while (i < flags->precision + 4 + (flags->precision == -1 * (!flags->bigl)))
	{
		n = (n - (intmax_t)n) * 16 * (-2 * (n < 0) + 1);
		flag = flags->capx * (((intmax_t)n % 16) > 9 && i != 0);
		str[i] = modu[(intmax_t)n] - flag * 32;
		i++;
	}
	countprec(flags, str);
	return (str);
=======
	i = 1;
	if (!modu[0])
		pf_initoa(modu);
	if (!(str = ft_memalloc(flags->precision + 2)))
		return (-1);
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[0] = flags->dpt * (flags->precision > 0);
	while (i < flags->precision + 2)
	{
		n = (n - (intmax_t)n) * 16 * (-2 * (n < 0) + 1);
		flag = flags->capx * (((intmax_t)n & 15) > 9 && i != 0);
		str[i] = modu[(intmax_t)n] - flag * 32;
		i++;
	}
	str[i] = 0;
	addnstr(str, countprec(flags, str), var);
	free(str);
	return (0);
>>>>>>> refs/remotes/origin/master
}
