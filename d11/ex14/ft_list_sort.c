/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:47:08 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 15:57:10 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

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
