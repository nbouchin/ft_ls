/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:35:37 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/15 15:35:39 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**time_argv(char **argv)
{
	return (argv);
}

char	**reverse(char **argv)
{
	char		*temp;
	int			i;

	i = 0;
	while (argv[i] && argv[i + 1])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) <= 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (argv);
}

char	**sort_argv(char **argv, t_lflag *f_s)
{
	argv = ft_sort_params(argv);
	if (f_s->flag_t)
		argv = time_argv(argv);
	if (f_s->flag_r)
		argv = reverse(argv);
	return (argv);
}

int		read_flag(char **argv, t_lflag **f_s, int argc, t_dirdata **dirdata)
{
	int	i;

	i = 1;
	while (argv[i][0] == '-' && ft_isalpha(argv[i][1]) && argv[i])
	{
		*f_s = flag_deal(&argv[i++], 0, *f_s);
		(*dirdata)->pass += 1;
		if (i == argc)
			break ;
	}
	return (i);
}
