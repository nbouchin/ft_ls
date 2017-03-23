/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:56:48 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 15:27:07 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lstrev(t_list **s, t_lflag *s_f)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	current = *s;
	prev = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	if (!s_f->flag_a)
		*s = prev;
	else
		*s = prev;
}

void	flag_r(t_list **s, t_lflag *s_f)
{
	(void)s_f;
	ft_lstrev(s, s_f);
}
