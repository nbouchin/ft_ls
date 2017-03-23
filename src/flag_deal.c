/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_deal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:46:27 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/22 09:36:39 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lflag		*flag_deal(char **argv, int nparam, t_lflag *f_s)
{
	size_t	i;

	i = 0;
	while (++i < ft_strlen(argv[nparam]))
	{
		if (argv[nparam][i] == 'l')
			f_s->flag_l = 1;
		else if (argv[nparam][i] == 'R')
			f_s->flag_re = 1;
		else if (argv[nparam][i] == 'a')
			f_s->flag_a = 1;
		else if (argv[nparam][i] == 't')
			f_s->flag_t = 1;
		else if (argv[nparam][i] == 'r')
			f_s->flag_r = 1;
		else
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			ft_putchar_fd(argv[nparam][i], 2);
			ft_putchar_fd('\n', 2);
			ft_putendl_fd("usage: ft_ls [-Ralrt] [file ...]", 2);
			exit(0);
		}
	}
	return (f_s);
}

void		get_error(char **argv, t_dirdata *data, int argc, int i)
{
	while (argv[i])
	{
		data->dirp = opendir(argv[i]);
		if (errno == ENOTDIR)
		{
			data->nparam++;
			data->checked = 1;
			i++;
			continue ;
		}
		if (!data->dirp && errno != ENOTDIR)
		{
			print_error2(argv[i], argc, data, 0);
			ft_bzero(argv[i], ft_strlen(argv[i]));
			i++;
		}
		else
		{
			closedir(data->dirp);
			i++;
		}
	}
}

void		put_file(char **argv, t_dirdata *data, int argc, t_lflag *f_s)
{
	int			i;
	t_arginfo	*test;

	i = 0;
	test = malloc(sizeof(t_arginfo));
	while (argv[i])
	{
		test->path_name = ft_strdup(argv[i]);
		lstat(test->path_name, &test->buf);
		if (!S_ISDIR(test->buf.st_mode))
		{
			p_dir(argv[i++], f_s, argc, data);
			data->nparam++;
		}
		else
			i++;
	}
	free(test->path_name);
	free(test);
}

void		init_flag_deal(char **argv, int argc, t_dirdata *data,
		t_lflag *f_s)
{
	int			i;
	t_arginfo	*test;

	i = 0;
	test = malloc(sizeof(t_arginfo));
	get_error(argv, data, argc, i);
	while (argv[i])
	{
		if (argv[i][0] != '\0')
		{
			test->path_name = ft_strdup(argv[i]);
			lstat(test->path_name, &test->buf);
			if (S_ISDIR(test->buf.st_mode) && p_dir(argv[i++], f_s, argc, data))
				data->nparam++;
			else
			{
				p_dir(argv[i++], f_s, argc, data);
				data->nparam++;
			}
		}
		else
			i++;
	}
	free(test->path_name);
	free(test);
}
