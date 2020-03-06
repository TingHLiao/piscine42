/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 21:10:02 by tliao             #+#    #+#             */
/*   Updated: 2019/08/22 22:03:32 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct	s_btree
{
	struct s_btree	*parent;
	struct s_btree	*right;
	struct s_btree	*left;
	void			*data;
}				t_btree;

typedef struct	s_list
{
	struct s_list	*next;
	t_btree			*node;
	int				lv;
}				t_list;

#endif
