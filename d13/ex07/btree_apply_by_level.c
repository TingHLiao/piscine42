/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 21:12:46 by tliao             #+#    #+#             */
/*   Updated: 2019/08/22 22:08:18 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int g_first[10000000];

t_list	*ft_create(t_btree *node, int lv)
{
	t_list *p;

	p = malloc(sizeof(t_list));
	p->node = node;
	p->lv = lv;
	p->next = 0;
	return (p);
}

void	ft_apply(t_list *list, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_btree *p;

	p = list->node;
	applyf(p->data, list->lv, !g_first[list->lv]);
	if (!g_first[list->lv])
		g_first[list->lv] = 1;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	if (!root)
		return ;
	head = ft_create(root, 0);
	tail = head;
	while (head)
	{
		ft_apply(head, applyf);
		if (head->node->left)
		{
			tail->next = ft_create(head->node->left, head->lv + 1);
			tail = tail->next;
		}
		if (head->node->right)
		{
			tail->next = ft_create(head->node->right, head->lv + 1);
			tail = tail->next;
		}
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
