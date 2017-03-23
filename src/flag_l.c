/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:32:02 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/22 09:39:43 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_pad		init_pad(void)
{
	t_pad	pad;

	pad.d1 = 0;
	pad.d2 = 0;
	pad.d3 = 0;
	pad.d4 = 0;
	pad.d5 = 0;
	pad.d6 = 0;
	pad.d7 = 0;
	pad.d8 = 0;
	pad.d9 = 0;
	return (pad);
}

t_pad		ft_pad(t_arginfo *arg, t_pad pad)
{
	char	*swap;

	if ((int)pad.d1 < ft_nblen(arg->buf.st_nlink))
		pad.d1 = ft_nblen(arg->buf.st_nlink);
	(arg->passwd) = getpwuid(arg->buf.st_uid);
	if (pad.d2 < ft_strlen(arg->passwd->pw_name))
		pad.d2 = ft_strlen(arg->passwd->pw_name);
	(arg->group) = getgrgid(arg->buf.st_gid);
	if (pad.d3 < ft_strlen(arg->group->gr_name))
		pad.d3 = ft_strlen(arg->group->gr_name);
	if ((int)pad.d4 < ft_nblen(arg->buf.st_size))
		pad.d4 = ft_nblen(arg->buf.st_size);
	if (pad.d5 < ft_strlen(swap =
				ft_strsub(ctime(&(arg->buf.st_mtimespec.tv_sec)), 4, 12)))
		pad.d5 = ft_strlen(swap);
	if (pad.d6 < ft_strlen(arg->d_name))
		pad.d6 = ft_strlen(arg->d_name);
	if ((int)pad.d8 < ft_nblen(major(arg->buf.st_rdev)))
		pad.d8 = ft_nblen(major(arg->buf.st_rdev));
	if ((int)pad.d9 < ft_nblen(minor(arg->buf.st_rdev)))
		pad.d9 = ft_nblen(minor(arg->buf.st_rdev));
	free(swap);
	return (pad);
}

void		ft_putpad(int i)
{
	while (i-- >= 0)
		ft_putchar(' ');
}

void		flag_l(t_list *s, t_lflag *f, t_pad pad)
{
	if_a(s, f, pad);
	if_na(s, f, pad);
}

int			count_total(t_list *s, t_lflag *f, int total)
{
	t_arginfo	*arg;

	arg = (((t_arginfo*)s->content));
	if (f->flag_l && f->flag_a)
		total += arg->buf.st_blocks;
	else if (f->flag_l && !f->flag_a)
		if (arg->d_name[0] != '.')
			total += arg->buf.st_blocks;
	return (total);
}
