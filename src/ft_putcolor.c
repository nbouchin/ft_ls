/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:55:08 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/09 13:14:55 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putstrcolor(char *str, mode_t md)
{
	if (S_ISDIR(md) && (md & S_IWOTH) && (md & S_ISVTX))
		ft_putstr(HGRN);
	if (S_ISDIR(md) && (md & S_IWOTH) && !(md & S_ISVTX))
		ft_putstr(HYEL);
	if (S_ISDIR(md) && !(md & S_IWOTH) && !(md & S_ISVTX))
		ft_putstr(BLU);
	if (S_ISREG(md) && (md & S_IXUSR) && (md & S_ISUID))
		ft_putstr(HRED);
	if (S_ISREG(md) && (md & S_IXUSR) && (md & S_ISGID))
		ft_putstr(HYEL);
	if (S_ISREG(md) && (md & S_IXUSR) &&
			!(md & S_ISGID) && !(md & S_ISUID))
		ft_putstr(RED);
	S_ISBLK(md) ? ft_putstr(HYEL) : 0;
	S_ISCHR(md) ? ft_putstr(HCYN) : 0;
	S_ISLNK(md) ? ft_putstr(MAG) : 0;
	S_ISFIFO(md) ? ft_putstr(YEL) : 0;
	S_ISSOCK(md) ? ft_putstr(GRN) : 0;
	ft_putstr(str);
	ft_putstr(RESET);
}
