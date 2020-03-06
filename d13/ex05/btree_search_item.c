/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:25:53 by tliao             #+#    #+#             */
/*   Updated: 2019/08/22 20:13:28 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *ans;

	if (root)
	{
		ans = btree_search_item(root->left, data_ref, cmpf);
		if (!ans)
			if (cmpf(root->data, data_ref) == 0)
				ans = root->data;
		if (!ans)
			ans = btree_search_item(root->right, data_ref, cmpf);
		return (ans);
	}
	return (0);
}
