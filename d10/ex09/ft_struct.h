/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:59:26 by tliao             #+#    #+#             */
/*   Updated: 2019/08/19 22:36:36 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

int				ft_add(int x, int y);
int				ft_sub(int x, int y);
int				ft_mul(int x, int y);
int				ft_div(int x, int y);
int				ft_mod(int x, int y);
int				ft_usage(int x, int y);

typedef struct	s_opp
{
	char	*op;
	int		(*f)(int, int);
}				t_opp;

#endif
