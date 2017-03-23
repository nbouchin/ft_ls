/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:35:11 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/22 09:43:39 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_right(t_arginfo *arg)
{
	print_usr(arg);
	print_grp(arg);
	print_oth(arg);
}

void		put_m(t_arginfo *arg, t_pad pad)
{
	if (!S_ISDIR(arg->buf.st_mode) && !S_ISLNK(arg->buf.st_mode)
			&& !S_ISREG(arg->buf.st_mode))
	{
		ft_putpad(pad.d8 - ft_nblen(major(arg->buf.st_rdev)));
		ft_putnbr(major(arg->buf.st_rdev));
		ft_putchar(',');
		ft_putpad(pad.d9 - ft_nblen(minor(arg->buf.st_rdev)));
		ft_putnbr(minor(arg->buf.st_rdev));
	}
	else
	{
		ft_putpad(pad.d8 - ft_nblen(major(arg->buf.st_rdev)) + 2);
		ft_putpad(pad.d9 - ft_nblen(minor(arg->buf.st_rdev)));
		ft_putnbr((arg->buf.st_size));
	}
}

void		u_g_right(t_arginfo *arg, t_pad pad)
{
	print_right(arg);
	ft_putpad(pad.d1 - ft_nblen(arg->buf.st_nlink));
	ft_putnbr(arg->buf.st_nlink);
	(arg->passwd) = getpwuid(arg->buf.st_uid);
	ft_putchar(' ');
	ft_putstr((arg->passwd->pw_name));
	ft_putpad(pad.d2 - ft_strlen(arg->passwd->pw_name));
	(arg->group) = getgrgid(arg->buf.st_gid);
	ft_putchar(' ');
	ft_putstr((arg->group->gr_name));
	ft_putpad(pad.d3 - ft_strlen(arg->group->gr_name) - 1);
	ft_putpad((pad.d4 - ft_nblen(arg->buf.st_size)) - 1);
	put_m(arg, pad);
	ft_putchar(' ');
	put_date(arg);
	ft_putchar(' ');
}

void		if_a(t_list *s, t_lflag *f, t_pad pad)
{
	t_arginfo		*arg;

	arg = (((t_arginfo*)s->content));
	if (f->flag_l && !f->flag_a)
	{
		if (arg->d_name[0] != '.')
		{
			if (S_ISDIR(arg->buf.st_mode))
				ft_putchar('d');
			else if (S_ISFIFO(arg->buf.st_mode))
				ft_putchar('p');
			else if (S_ISCHR(arg->buf.st_mode))
				ft_putchar('c');
			else if (S_ISBLK(arg->buf.st_mode))
				ft_putchar('b');
			else if (S_ISSOCK(arg->buf.st_mode))
				ft_putchar('s');
			else
				(S_ISLNK(arg->buf.st_mode)) ? ft_putchar('l') : ft_putchar('-');
			u_g_right(arg, pad);
		}
		return ;
	}
}

void		if_na(t_list *s, t_lflag *f, t_pad pad)
{
	t_arginfo		*arg;

	arg = (((t_arginfo*)s->content));
	if (f->flag_l && f->flag_a)
	{
		if (S_ISDIR(arg->buf.st_mode))
			ft_putchar('d');
		else if (S_ISFIFO(arg->buf.st_mode))
			ft_putchar('p');
		else if (S_ISCHR(arg->buf.st_mode))
			ft_putchar('c');
		else if (S_ISBLK(arg->buf.st_mode))
			ft_putchar('b');
		else if (S_ISSOCK(arg->buf.st_mode))
			ft_putchar('s');
		else
			(S_ISLNK(arg->buf.st_mode)) ? ft_putchar('l') : ft_putchar('-');
		u_g_right(arg, pad);
		return ;
	}
}
