/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:35:19 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 17:14:53 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int		ft_check(t_list **begin_list, t_list *insert, int (*cmp)())
{
	t_list *p;

	p = *begin_list;
	if (!(*begin_list))
	{
		*begin_list = insert;
		return (0);
	}
	if ((*cmp)(p->data, insert->data) > 0)
	{
		insert->next = p;
		*begin_list = insert;
		return (0);
	}
	return (1);
}

void	ft_push(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *p;
	t_list *insert;

	p = *begin_list;
	insert = malloc(sizeof(t_list));
	insert->data = data;
	insert->next = NULL;
	if (!ft_check(begin_list, insert, cmp))
		return ;
	while (p->next)
	{
		if ((*cmp)(p->data, data) < 0 && (*cmp)(p->next->data, data) > 0)
		{
			insert->next = p->next;
			p->next = insert;
			return ;
		}
		p = p->next;
	}
	p->next = insert;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*p;
	t_list	*m;
	void	*sort;

	p = *begin_list;
	while (p)
	{
		m = *begin_list;
		while (m->next)
		{
			if ((*cmp)(m->data, m->next->data) > 0)
			{
				sort = m->data;
				m->data = m->next->data;
				m->next->data = sort;
			}
			m = m->next;
		}
		p = p->next;
	}
	ft_push(begin_list, data, cmp);
}
