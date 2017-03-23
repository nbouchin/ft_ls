/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:15:32 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 11:20:56 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_list	*min_arg(t_list *list)
{
	t_list	*swap;
	t_list	*min;

	min = list;
	swap = list;
	while (swap)
	{
		if (ft_strcmp(((t_arginfo*)min->content)->d_name,
					((t_arginfo*)swap->content)->d_name) > 0)
			min = swap;
		swap = swap->next;
	}
	return (min);
}

void			alpha_sort(t_list **link_i)
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

void			order_file(t_list **s, t_lflag *f_s)
{
	(void)f_s;
	alpha_sort(s);
}
