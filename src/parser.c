/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:59:43 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/22 09:36:52 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		sort_data(t_lflag *f_s, int total, t_list **s, t_list **save)
{
	(*s) = (*s)->next;
	(f_s->flag_l) ? print_total(total, *s, *save) : 0;
	order_file(s, f_s);
	(f_s->flag_t) ? flag_t(s, f_s) : 0;
	(f_s->flag_r) ? flag_r(s, f_s) : 0;
}

void		padding(t_dirdata **dirdata, int *argc, t_lflag **f_s, t_list **s)
{
	t_list	*save;

	save = (*s)->next;
	lputspace(*dirdata, *argc, *f_s, save);
	print_file_name(*argc, *dirdata, *f_s);
}

void		recursive(t_list **s, t_lflag *f_s, int argc, t_dirdata **dirdata)
{
	t_list	*save;

	save = (*s)->next;
	closedir((*dirdata)->dirp);
	do_ls(&save, f_s, argc, dirdata);
}

int			p_dir(char *str, t_lflag *f_s, int argc, t_dirdata *dirdata)
{
	t_list			*save;
	static int		total;
	t_arginfo		*arginfo;
	t_list			*s;

	dirdata->file_to_open = ft_strdup(str);
	dirdata = init_data(&arginfo, &s, &save, &dirdata);
	dirdata->dirp = opendir(str);
	if (errno == ENOTDIR && !dirdata->dirp)
		return (print_error(arginfo, s, f_s, dirdata));
	else if ((errno == ENOTDIR && !dirdata->dirp) || !dirdata->dirp)
		return (print_error2(str, argc, dirdata, f_s->flag_re));
	while ((dirdata->dirent = readdir(dirdata->dirp)))
	{
		init_arginfo(arginfo, s, str, dirdata->dirent->d_name);
		(f_s->flag_l) ? (total = count_total(s, f_s, total)) : 0;
		dirdata->pad = ft_pad((((t_arginfo*)s->content)), dirdata->pad);
	}
	padding(&dirdata, &argc, &f_s, &s);
	sort_data(f_s, total, &s, &save);
	print_file(&s, f_s, dirdata->pad, &total);
	recursive(&s, f_s, argc, &dirdata);
	return (clean(&s, arginfo));
}

void		lparser(int argc, char **argv)
{
	t_lflag			*f_s;
	t_dirdata		*dirdata;
	int				i;

	i = 0;
	dirdata = ft_memalloc(sizeof(t_dirdata));
	dirdata->pass = 0;
	dirdata->nparam = 0;
	f_s = ft_memalloc(sizeof(t_lflag));
	if (argc == 1)
	{
		p_dir(".", f_s, argc, dirdata);
		exit(0);
	}
	else
		i = read_flag(argv, &f_s, argc, &dirdata);
	argv += i;
	if (argc == i && (dirdata->nparam = 1))
		p_dir(".", f_s, argc, dirdata);
	if (*argv && (argv = sort_argv(argv, f_s)))
		init_flag_deal(argv, argc, dirdata, f_s);
	free(f_s);
	free(dirdata->file_to_open);
	free(dirdata);
}
