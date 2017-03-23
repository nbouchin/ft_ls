/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:05:56 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/22 09:43:44 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# define HCYN	"\x1B[33;7m"
# define HYEL	"\x1B[36;7m"
# define HGRN   "\x1B[32;7m"
# define HRED	"\x1B[31;7m"
# define MAG	"\x1B[35;1m"
# define YEL	"\x1B[33;1m"
# define GRN	"\x1B[32;1m"
# define BLU	"\x1B[36;1m"
# define RED	"\x1B[31;1m"
# define RESET	"\x1B[36;0m"

typedef struct		s_pad
{
	size_t			d1;
	size_t			d2;
	size_t			d3;
	size_t			d4;
	size_t			d5;
	size_t			d6;
	size_t			d7;
	size_t			d8;
	size_t			d9;
}					t_pad;

typedef struct		s_arginfo
{
	char			*d_name;
	struct stat		buf;
	struct passwd	*passwd;
	struct group	*group;
	char			*path_name;
}					t_arginfo;

typedef struct		s_lflag
{
	int				flag_l;
	int				flag_re;
	int				flag_a;
	int				flag_r;
	int				flag_t;
}					t_lflag;

typedef struct		s_dirdata
{
	DIR				*dirp;
	struct dirent	*dirent;
	t_pad			pad;
	char			*file_to_open;
	int				pass;
	int				nparam;
	int				checked;
}					t_dirdata;

void				lparser(int argc, char **argv);
void				flag_a(t_list *stock, t_lflag *flag_struct);
void				flag_l(t_list *stock, t_lflag *flag_struct, t_pad pad);
void				flag_t(t_list **stock, t_lflag *flag_struct);
void				flag_r(t_list **stock, t_lflag *flag_struct);
int					count_total(t_list *stock, t_lflag *flag_struct, int total);
int					print_file(t_list **list, t_lflag *flag_struct, t_pad pad,
		int *total);
void				order_file(t_list **list, t_lflag *flag_struct);
void				ft_del(void *content, size_t content_size);
t_pad				init_pad(void);
t_pad				ft_pad(t_arginfo *arg, t_pad pad);
void				ft_putpad(int i);
void				ls_parser(int argc, char **argv);
void				print_usr(t_arginfo *arg);
void				print_grp(t_arginfo *arg);
void				print_oth(t_arginfo *arg);
void				if_a(t_list *s, t_lflag *f, t_pad pad);
void				if_na(t_list *s, t_lflag *f, t_pad pad);
void				u_g_right(t_arginfo *arg, t_pad pad);
void				put_m(t_arginfo *arg, t_pad pad);
void				print_right(t_arginfo *arg);
void				do_ls(t_list **s, t_lflag *f_s, int argc, t_dirdata **data);
int					p_dir(char *str, t_lflag *f_s, int argc, t_dirdata *data);
int					print_error(t_arginfo *arginfo, t_list *s, t_lflag *f_s,
		t_dirdata *dirdata);
void				init_arginfo(t_arginfo *arg, t_list *s, char *file,
		char *d_name);
int					print_error2(char *str, int argc, t_dirdata *data, int f_s);
void				print_total(int total, t_list *s, t_list *save);
void				print_file_name(int argc, t_dirdata *data, t_lflag *f_s);
char				*init_path(char *d_name, char *path);
t_dirdata			*init_data(t_arginfo **arginfo, t_list **s, t_list **save,
		t_dirdata **data);
t_lflag				*flag_deal(char **argv, int nparam, t_lflag *f_s);
void				init_flag_deal(char **argv, int argc, t_dirdata *data,
		t_lflag *f_s);
void				lputspace(t_dirdata *dirdata, int argc, t_lflag *f_s,
		t_list *s);
int					read_flag(char **argv, t_lflag **f_s, int argc,
		t_dirdata **dirdata);
void				ft_putstrcolor(char *str, mode_t md);
int					clean(t_list **s, t_arginfo *arginfo);
void				put_date(t_arginfo *arg);
char				**sort_argv(char **argv, t_lflag *f_s);

#endif
