/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:47:53 by tliao             #+#    #+#             */
/*   Updated: 2019/08/22 16:22:46 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree *btree_create_node(void *item);

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree *p;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	p = *root;
	if (cmpf(item, p->data) >= 0)
	{
		if (p->right)
			btree_insert_data(&(p->right), item, cmpf);
		else
			p->right = btree_create_node(item);
	}
	else
	{
		if (p->left)
			btree_insert_data(&(p->left), item, cmpf);
		else
			p->left = btree_create_node(item);
	}
}
