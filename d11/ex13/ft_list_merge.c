/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:32:07 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 14:38:48 by tliao            ###   ########.fr       */
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
