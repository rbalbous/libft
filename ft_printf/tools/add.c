/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:33:39 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/05 12:20:49 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2017/12/18 18:22:44 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
void	clean_buff(t_var *var)
{
	if (!var->string)
		write(var->fd, var->buf, var->bufindex);
	else
		pf_memcpy(var->string, var->buf, var->bufindex);
	var->alwritten += var->bufindex;
	var->bufindex = 0;
}

int		addnull(t_flags *flags, t_var *var)
{
	int n;

	n = 6;
	if (flags->precision < 6 && flags->isp)
		n = flags->precision;
	if (var->bufindex + n > BUFF_SIZE - 1)
		clean_buff(var);
	addnstr("(null)", n, var);
=======
int		addnull(t_var *var)
{
	var->buf[var->bufindex] = '(';
	var->bufindex++;
	var->buf[var->bufindex] = 'n';
	var->bufindex++;
	var->buf[var->bufindex] = 'u';
	var->bufindex++;
	var->buf[var->bufindex] = 'l';
	var->bufindex++;
	var->buf[var->bufindex] = 'l';
	var->bufindex++;
	var->buf[var->bufindex] = ')';
	var->bufindex++;
>>>>>>> refs/remotes/origin/master
	return (0);
}

int		addmchar(char c, t_var *var, int len)
{
	while (len-- > 0)
	{
		var->buf[var->bufindex] = c;
		var->bufindex++;
<<<<<<< HEAD
		if (var->bufindex == BUFF_SIZE - 1)
			clean_buff(var);
=======
>>>>>>> refs/remotes/origin/master
	}
	return (0);
}

void	addchar(const char c, t_var *var)
{
<<<<<<< HEAD
	if (var->bufindex + 1 > BUFF_SIZE - 1)
		clean_buff(var);
=======
>>>>>>> refs/remotes/origin/master
	var->buf[var->bufindex] = c;
	var->bufindex++;
	return ;
}

<<<<<<< HEAD
=======
void	addstr(char *str, t_var *var)
{
	int i;

	i = 0;
	while (str[i])
	{
		var->buf[var->bufindex] = str[i];
		var->bufindex++;
		i++;
	}
	return ;
}

>>>>>>> refs/remotes/origin/master
void	addnstr(void *str, size_t len, t_var *var)
{
	size_t	i;
	char	*tmp;

	tmp = str;
	i = 0;
	while (len > i)
	{
		var->buf[var->bufindex] = tmp[i];
		i++;
		var->bufindex++;
<<<<<<< HEAD
		if (var->bufindex + len > BUFF_SIZE - 1)
			clean_buff(var);
=======
>>>>>>> refs/remotes/origin/master
	}
	return ;
}
