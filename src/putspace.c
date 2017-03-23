/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putspace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:15:43 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/22 09:37:22 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	lputspace(t_dirdata *dirdata, int argc, t_lflag *f_s, t_list *s)
{
	static int	i;

	(void)s;
	if (dirdata->nparam >= 2)
	{
		ft_putendl("");
		return ;
	}
	if ((dirdata->nparam != 0 && (dirdata->nparam != argc - 1)) && i != 0)
		ft_putendl("");
	else if ((f_s->flag_re) && argc - dirdata->pass - 1 <= 2 && i != 0)
		ft_putendl("");
	i++;
	return ;
}
