/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:15:49 by xzhu              #+#    #+#             */
/*   Updated: 2018/10/02 16:18:51 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libftprintf/includes/libft.h"
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/get_next_line.h"

typedef	struct	s_ls
{
	char		invalid;
	uint32_t	arg_used;
	uint8_t		rec;
	uint8_t		all;
	uint8_t		list;
	uint8_t		rev;
	uint8_t		time;
}				t_ls;

#endif
