/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:42:24 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/04 16:08:40 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2017/12/18 22:49:22 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_memcpy(void *dest, const void *src, int n)
{
	char	*dd;
	char	*ss;
	int		i;
<<<<<<< HEAD
	int		index;

	i = 0;
	index = 0;
	dd = (char*)dest;
	ss = (char*)src;
	while (dd[index])
		index++;
	while (i < n)
	{
		dd[index + i] = ss[i];
		i++;
	}
	dd[n + index] = 0;
=======

	i = 0;
	dd = (char*)dest;
	ss = (char*)src;
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	dd[n] = 0;
>>>>>>> refs/remotes/origin/master
	return (n);
}
