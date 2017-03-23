/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:42:40 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 14:45:31 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*init_path(char *d_name, char *path)
{
	char	*path_name;

	path_name = ft_strjoin(path, "/");
	path_name = ft_realloc(path_name, ft_strlen(d_name));
	path_name = ft_strcat(path_name, d_name);
	return (path_name);
}

void		init_arginfo(t_arginfo *arg, t_list *s, char *file, char *d_name)
{
	s->content = arg;
	((t_arginfo*)s->content)->d_name = ft_strdup(d_name);
	if (!(errno == ENOTDIR))
		((t_arginfo*)s->content)->path_name =
			init_path(d_name, file);
	else
		((t_arginfo*)s->content)->path_name = ft_strdup(d_name);
	lstat(((t_arginfo*)s->content)->path_name, &arg->buf);
	ft_lstaddend(&s, ft_lstnew(arg, sizeof(t_arginfo)));
}

t_dirdata	*init_data(t_arginfo **arginfo, t_list **s, t_list **save,
		t_dirdata **dirdata)
{
	(*dirdata)->pad = init_pad();
	*arginfo = ft_memalloc(sizeof(t_arginfo));
	*s = ft_lstnew(*arginfo, sizeof(t_arginfo));
	*save = *s;
	return (*dirdata);
}
