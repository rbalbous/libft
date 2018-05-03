/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:54:48 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/05 12:36:09 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/19 15:55:08 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf(int fd, const char *str, ...)
{
	static int	(*f[256])() = {NULL};
	va_list		ap;
	t_var		var;
<<<<<<< HEAD

	va_start(ap, str);
	if (initialise_var(&var, ap, f, (char*)str))
		return (-1);
	var.fd = fd;
=======
	int			ret;

	va_start(ap, str);
	initialise_var(&var, ap, f);
>>>>>>> refs/remotes/origin/master
	while (str[++var.index])
	{
		if (str[var.index] == '%' && str[var.index + 1])
		{
<<<<<<< HEAD
			if ((var.ret = parse((t_uint8*)str, &var, ap, f)) < 0)
			{
				if (var.ret == -2)
=======
			if ((ret = parse((t_uint8*)str, &var, ap, f)) < 0)
			{
				if (ret == -2)
>>>>>>> refs/remotes/origin/master
					break ;
				return (pf_parserror(&var, ap));
			}
			var.error = var.bufindex;
		}
		else if (str[var.index] != '%')
			addchar(str[var.index], &var);
	}
	va_end(ap);
	return (write(fd, var.buf, var.bufindex));
}
