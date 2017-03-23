/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:31:33 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 11:39:01 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		put_date(t_arginfo *arg)
{
	time_t			test;
	char			*date;
	char const		*ret;
	char			*swap;

	ret = ctime(&(arg->buf.st_mtimespec.tv_sec));
	date = ft_strdup(ret);
	if (((time_t)time(&test) - (arg->buf.st_mtimespec.tv_sec)) >= 15770000)
	{
		swap = ft_strsub(date, 4, 6);
		ft_putstr(swap);
		ft_putchar(' ');
		ft_strdel(&swap);
		swap = ft_strsub(date, 19, 5);
		ft_putstr(swap);
		ft_strdel(&swap);
	}
	else
	{
		swap = ft_strsub(date, 4, 12);
		ft_putstr(swap);
		ft_strdel(&swap);
	}
	ft_strdel(&date);
}
