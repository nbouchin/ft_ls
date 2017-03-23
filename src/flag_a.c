/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:20:09 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/09 14:09:23 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_link(t_list *s)
{
	char *buf;

	buf = malloc(1024);
	ft_bzero(buf, 1024);
	readlink(((t_arginfo*)s->content)->path_name, buf, 1024);
	ft_putstr(" -> ");
	ft_putstr(buf);
	free(buf);
}

void	flag_a(t_list *s, t_lflag *flag_struct)
{
	if (!flag_struct->flag_a)
	{
		if (((t_arginfo*)s->content)->d_name[0] != '.')
		{
			ft_putstrcolor(((t_arginfo*)s->content)->d_name,
					((t_arginfo*)s->content)->buf.st_mode);
			if (flag_struct->flag_l)
				if (S_ISLNK(((t_arginfo*)s->content)->buf.st_mode))
					print_link(s);
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putstrcolor(((t_arginfo*)s->content)->d_name,
				((t_arginfo*)s->content)->buf.st_mode);
		if (flag_struct->flag_l)
			if (S_ISLNK(((t_arginfo*)s->content)->buf.st_mode))
				print_link(s);
		ft_putchar('\n');
	}
}
