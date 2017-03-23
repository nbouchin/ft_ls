/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:40:46 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/22 09:36:23 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		do_ls(t_list **s, t_lflag *f, int a, t_dirdata **d)
{
	t_list		*save;

	save = (*s);
	while (save)
	{
		if (((f->flag_re &&
						ft_strcmp(((t_arginfo*)(save)->content)->d_name, ".."))
				!= 0) && (f->flag_re &&
					ft_strcmp(((t_arginfo*)(save)->content)->d_name, ".") != 0))
			if (S_ISDIR(((t_arginfo*)(save)->content)->buf.st_mode))
			{
				if (!f->flag_a &&
						((t_arginfo*)(save)->content)->d_name[0] != '.')
					p_dir(((t_arginfo*)(save)->content)->path_name, f, a, *d);
				else if (f->flag_a)
					p_dir(((t_arginfo*)(save)->content)->path_name, f, a, *d);
			}
		save = (save)->next;
	}
}
