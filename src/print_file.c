/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:03:31 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 15:37:01 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		print_file(t_list **save, t_lflag *f_s, t_pad pad, int *total)
{
	t_list	*swap;

	swap = (*save);
	if (*total == -1)
	{
		flag_l(swap, f_s, pad);
		flag_a(swap, f_s);
		return (0);
	}
	while (swap)
	{
		flag_l(swap, f_s, pad);
		flag_a(swap, f_s);
		*total = 0;
		swap = swap->next;
	}
	return (1);
}
