/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:56:54 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 14:25:31 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_check(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *cur;
	t_list *prev;
	t_list *rm;

	prev = *begin_list;
	cur = prev->next;
	while ((*cmp)(prev->data, data_ref) == 0 && cur)
	{
		rm = prev;
		prev = prev->next;
		cur = prev->next;
		*begin_list = prev;
		free(rm);
	}
	if ((*cmp)(prev->data, data_ref) == 0)
	{
		free(prev);
		*begin_list = NULL;
	}
	return (*begin_list);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *cur;
	t_list *prev;
	t_list *rm;

	if (!(*begin_list))
		return ;
	prev = ft_check(begin_list, data_ref, cmp);
	if (!prev)
		return ;
	cur = prev->next;
	while (cur)
	{
		if ((*cmp)(cur->data, data_ref) == 0)
		{
			rm = cur;
			prev->next = cur->next;
			cur = cur->next;
			free(rm);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
