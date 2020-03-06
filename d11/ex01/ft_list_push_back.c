/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:34:24 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 10:54:14 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *p;

	p = *begin_list;
	if (!p)
	{
		*begin_list = malloc(sizeof(t_list));
		(*begin_list)->data = data;
		(*begin_list)->next = NULL;
		return ;
	}
	while (p->next)
		p = p->next;
	p->next = malloc(sizeof(t_list));
	p->next->data = data;
	p->next->next = NULL;
}
