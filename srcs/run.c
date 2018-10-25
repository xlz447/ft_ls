/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:21:28 by xzhu              #+#    #+#             */
/*   Updated: 2018/10/25 16:21:39 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	run(t_ls *ls, int ac, char **av)
{
	ft_printf("|%i| args need to print\n", (int)ls->args_still_need_print);
	if (ac - 1 == (int)ls->arg_used)
		ft_printf("trying .\n");
	while (ac - ++ls->arg_used > 0)
		ft_printf("trying %s\n", av[ls->arg_used]);
}
