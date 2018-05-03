/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_w.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 21:19:31 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/22 15:24:34 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/01/17 17:30:33 by rbalbous         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
void		encoding(char *s, char **result, int keylen, t_flags *flags)
{
	int		ind;
	int		i;
	int		slash;

	ind = -1;
	i = 0;
	slash = 0;
	while (++ind < flags->len)
	{
		i *= (i != keylen);
		(*result)[ind + slash] = (KEY[i] + s[ind] - 64) % 95 + 32;
		if ((*result)[ind + slash] == '\\')
		{
			slash++;
			(*result)[ind + slash] = '\\';
			flags->len++;
		}
		i++;
	}
	(*result)[ind + slash] = 0;
}

=======
>>>>>>> refs/remotes/origin/master
int			pf_w(t_flags *flags, t_var *var, va_list ap)
{
	char	*s;
	char	*result;
	int		keylen;
<<<<<<< HEAD

	s = va_arg(ap, char*);
	if (s == NULL)
		return (pf_isnull(flags, var));
	flags->len = ft_strlen(s);
	keylen = ft_strlen(KEY);
	if (!(result = malloc(sizeof(*result) * (2 * flags->len + 1))))
		return (-1);
	encoding(s, &result, keylen, flags);
=======
	int		ind;
	int		i;

	s = va_arg(ap, char*);
	flags->len = ft_strlen(s);
	keylen = ft_strlen(KEY);
	ind = 0;
	i = 0;
	if (!(result = malloc(sizeof(*result) * (flags->len + 1))))
		return (-1);
	while (ind < flags->len)
	{
		i *= (i != keylen);
		result[ind] = (KEY[i] + s[ind] - 64) % 95 + 32;
		ind++;
		i++;
	}
	result[ind] = 0;
>>>>>>> refs/remotes/origin/master
	addnstr(result, flags->len, var);
	free(result);
	return (0);
}
