/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:39:27 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/22 09:37:11 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_total(int total, t_list *s, t_list *save)
{
	ft_putstr("total ");
	ft_putnbr(total);
	if (s == save->next)
		ft_putchar('\n');
}

void		print_file_name(int argc, t_dirdata *data, t_lflag *f_s)
{
	static int	i;

	if (((argc - 1 > data->pass + 1) || (argc > 2 && data->pass == 0))
			&& !f_s->flag_re)
		ft_putendl(ft_strjoin(data->file_to_open, ":"));
	if (f_s->flag_re && i != 0)
		ft_putendl(ft_strjoin(data->file_to_open, ":"));
	if (f_s->flag_re)
		i = 1;
}
