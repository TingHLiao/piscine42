/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:42:07 by tliao             #+#    #+#             */
/*   Updated: 2019/08/23 16:18:42 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree_rb.h"

int g_flag;

t_rb_node	*ft_create(void *data, int color)
{
	t_rb_node *p;

	p = malloc(sizeof(t_rb_node));
	p->parent = 0;
	p->left = 0;
	p->right = 0;
	p->data = data;
	p->color = color;
	return (p);
}

void		ft_right(t_rb_node **root, t_rb_node *m, t_rb_node **in)
{
	t_rb_node *p;

	*in = m;
	p = m->left;
	m->left = p->right;
	if (p->right)
		p->right->parent = m;
	p->parent = m->parent;
	if (!m->parent)
		*root = p;
	else if (m == m->parent->left)
		m->parent->left = p;
	else
		m->parent->right = p;
	p->right = m;
	m->parent = p;
}

void		ft_left(t_rb_node **root, t_rb_node *p, t_rb_node **in)
{
	t_rb_node *m;

	*in = p;
	m = p->right;
	p->right = m->left;
	if (m->left)
		m->left->parent = p;
	m->parent = p->parent;
	if (!p->parent)
		*root = m;
	else if (p == p->parent->left)
		p->parent->left = m;
	else
		p->parent->right = m;
	m->left = p;
	p->parent = m;
}

void		ft_check(t_rb_node **root, t_rb_node *in, t_rb_node *p)
{
	t_rb_node *un;
	t_rb_node *g;

	while ((in != *root) && (p->color == RB_RED))
	{
		p = in->parent;
		g = p->parent;
		un = (p == g->left) ? g->right : g->left;
		g_flag = (un->color == 1) ? 0 : 1;
		if (g_flag && p == g->left && in == p->right)
			ft_left(root, p, &in);
		if (g_flag && p == g->right && in == p->left)
			ft_right(root, p, &in);
		p = in->parent;
		un->color = 0;
		p->color = 0;
		g->color = 1;
		if (g_flag && p == g->left)
			ft_right(root, g, &in);
		if (g_flag && p == g->right)
			ft_left(root, g, &in);
		in = g;
	}
	(*root)->color = RB_BLACK;
}

void		rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *))
{
	t_rb_node *ch;
	t_rb_node *par;
	t_rb_node *insert;

	if (!*root)
	{
		*root = ft_create(data, 0);
		return ;
	}
	insert = ft_create(data, 1);
	ch = *root;
	while (ch)
	{
		par = ch;
		if (cmpf(data, par->data) >= 0)
			ch = ch->right;
		else
			ch = ch->left;
	}
	insert->parent = par;
	if (cmpf(data, par->data) >= 0)
		par->right = insert;
	else
		par->left = insert;
	ft_check(root, insert, par);
}
