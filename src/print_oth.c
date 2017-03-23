/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:22:10 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/08 15:04:45 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_usr(t_arginfo *arg)
{
	(arg->buf.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(arg->buf.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	if (!(arg->buf.st_mode & S_IXUSR) && !(arg->buf.st_mode & S_ISUID))
		ft_putchar('-');
	else if ((arg->buf.st_mode & S_IXUSR) && !(arg->buf.st_mode & S_ISUID))
		ft_putchar('x');
	else if (!(arg->buf.st_mode & S_IXUSR) && arg->buf.st_mode & S_ISUID)
		ft_putchar('S');
	else
		ft_putchar('s');
}

void		print_grp(t_arginfo *arg)
{
	(arg->buf.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(arg->buf.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	if (!(arg->buf.st_mode & S_IXGRP) && !(arg->buf.st_mode & S_ISGID))
		ft_putchar('-');
	else if ((arg->buf.st_mode & S_IXGRP) && !(arg->buf.st_mode & S_ISGID))
		ft_putchar('x');
	else if (!(arg->buf.st_mode & S_IXGRP) && arg->buf.st_mode & S_ISGID)
		ft_putchar('S');
	else
		ft_putchar('s');
}

void		print_oth(t_arginfo *arg)
{
	(arg->buf.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(arg->buf.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	if (!(arg->buf.st_mode & S_IXOTH) && !(arg->buf.st_mode & S_ISVTX))
		ft_putchar('-');
	else if ((arg->buf.st_mode & S_IXOTH) && !(arg->buf.st_mode & S_ISVTX))
		ft_putchar('x');
	else if (!(arg->buf.st_mode & S_IXOTH) && arg->buf.st_mode & S_ISVTX)
		ft_putchar('T');
	else
		ft_putchar('t');
}
