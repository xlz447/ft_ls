/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:20:40 by xzhu              #+#    #+#             */
/*   Updated: 2018/10/02 16:21:05 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	set_flags(t_ls *ls, char c)
{
	if (c == 'R')
		ls->rec = 1;
	else if (c == 'a')
		ls->all = 1;
	else if (c == 'l')
		ls->list = 1;
	else if (c == 'r')
		ls->rev = 1;
	else if (c == 't')
		ls->time = 1;
}

static int	parse(t_ls *ls, int ac, char **av)
{
	int i;
	int j;

	i = 0;
	ls->arg_used = 0;
	while (--ac > 0 && av[++i][0] == '-')
	{
		j = 0;
		while (av[i][++j] != '\0')
		{
			if (!ft_strchr("Ralrt", av[i][j]))
			{
				ls->invalid = av[i][j];
				return (0);
			}
			else
				set_flags(ls, av[i][j]);
		}
		if (j == 1)
			break ;
		ls->arg_used++;
	}
	ls->args_still_need_print = ac;
	ls->args = av + i;
	if (ls->rec)
		ft_printf("R flag set\n");
	if (ls->all)
		ft_printf("a flag set\n");
	if (ls->list)
		ft_printf("l flag set\n");
	if (ls->rev)
		ft_printf("r flag set\n");
	if (ls->time)
		ft_printf("t flag set\n");
	return (1);
}

int			main(int argc, char **argv)
{
	t_ls ls;

	ft_memset(&ls, 0, sizeof(t_ls));
	if (parse(&ls, argc, argv))
		run(&ls, argc, argv);
	else
		ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls %s [file ...]\n",
			ls.invalid, "[-Ralrt]");
	return (0);
}
