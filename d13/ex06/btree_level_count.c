/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:55:33 by tliao             #+#    #+#             */
/*   Updated: 2019/08/22 17:09:22 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	if (btree_level_count(root->right) > btree_level_count(root->left))
		return (1 + btree_level_count(root->right));
	else
		return (1 + btree_level_count(root->left));
}
