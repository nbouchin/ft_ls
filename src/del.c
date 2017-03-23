/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:47:11 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 11:59:02 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		clean(t_list **s, t_arginfo *arginfo)
{
	t_list	*swap;

	swap = ((*s)->next);
	free((*s));
	ft_lstdel(&swap, ft_del);
	free(arginfo);
	return (1);
}
