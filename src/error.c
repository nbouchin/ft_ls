/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:33:35 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 11:29:05 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		print_error(t_arginfo *arginfo, t_list *s,
		t_lflag *f_s, t_dirdata *dirdata)
{
	int		total;

	if (!opendir(dirdata->file_to_open) && dirdata->checked != 1 &&
			errno == ENOTDIR)
	{
		perror(dirdata->file_to_open);
		dirdata->checked = 0;
		return (0);
	}
	total = -1;
	init_arginfo(arginfo, s, dirdata->file_to_open, dirdata->file_to_open);
	dirdata->pad = ft_pad(((t_arginfo*)s->content), dirdata->pad);
	return (print_file(&s, f_s, dirdata->pad, &total));
}

int		print_error2(char *str, int argc, t_dirdata *data, int f_s)
{
	(void)data;
	(void)str;
	(void)argc;
	if ((f_s && errno != ENOTDIR) || (errno != EACCES && f_s))
	{
		ft_putendl("");
		ft_putstr(str);
		ft_putendl(":");
	}
	if (str[0] == '\0')
		return (0);
	else if (!data->dirp && errno == ENOTDIR)
	{
		ft_putendl("");
		ft_putstr(str);
		ft_putendl(":");
		perror(str);
	}
	else
	{
		perror(str);
		return (0);
	}
	return (0);
}
