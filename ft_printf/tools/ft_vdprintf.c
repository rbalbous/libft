/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:23:53 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/05 12:46:37 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/19 16:07:00 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vdprintf(int fd, const char *str, va_list ap)
{
	static int	(*f[256])() = {NULL};
	t_var		var;
	int			ret;

<<<<<<< HEAD
	if (initialise_var(&var, ap, f, (char*)str))
		return (-1);
	var.fd = fd;
=======
	initialise_var(&var, ap, f);
>>>>>>> refs/remotes/origin/master
	while (str[++var.index])
	{
		if (str[var.index] == '%' && str[var.index + 1])
		{
			if ((ret = parse((t_uint8*)str, &var, ap, f)) < 0)
			{
				if (ret == -2)
					break ;
				return (pf_parserror(&var, ap));
			}
			var.error = var.bufindex;
		}
		else if (str[var.index] != '%')
			addchar(str[var.index], &var);
	}
	return (write(fd, var.buf, var.bufindex));
}
