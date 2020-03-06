/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 22:32:24 by tliao             #+#    #+#             */
/*   Updated: 2019/08/23 16:21:31 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_RB_H
# define FT_BTREE_RB_H

enum	e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct	s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*right;
	struct s_rb_node	*left;
	void				*data;
	enum e_rb_color		color;
}				t_rb_node;

#endif
