/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:03:06 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 15:02:25 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_list		*min_arg(t_list *list)
{
	t_list	*swap;
	t_list	*min;

	min = list;
	swap = list;
	while (swap)
	{
		if ((((t_arginfo*)min->content)->buf.st_mtimespec.tv_sec) -
				(((t_arginfo*)swap->content)->buf.st_mtimespec.tv_sec) < 0)
			min = swap;
		swap = swap->next;
	}
	return (min);
}

void				time_sort(t_list **link_i)
{
	void		*swap;
	t_list		*tmp;
	t_list		*min;

	tmp = *link_i;
	if (!tmp)
		return ;
	while (tmp)
	{
		min = min_arg(tmp);
		swap = min->content;
		min->content = tmp->content;
		tmp->content = swap;
		tmp = tmp->next;
	}
}

void				flag_t(t_list **s, t_lflag *f_s)
{
	(void)f_s;
	time_sort(s);
}
