/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:50:07 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 11:59:08 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_del(void *content, size_t content_size)
{
	(void)content_size;
	free(((t_arginfo*)content)->d_name);
	free(((t_arginfo*)content)->path_name);
	free(content);
	(void)content;
	return ;
}
