/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:17:17 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 17:39:34 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *p;

	p = *begin_list1;
	if (!p)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (p->next)
		p = p->next;
	p->next = begin_list2;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*p;
	t_list	*m;
	void	*data;

	p = *begin_list;
	while (p)
	{
		m = *begin_list;
		while (m->next)
		{
			if ((*cmp)(m->data, m->next->data) > 0)
			{
				data = m->data;
				m->data = m->next->data;
				m->next->data = data;
			}
			m = m->next;
		}
		p = p->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
