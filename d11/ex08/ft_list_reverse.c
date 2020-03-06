/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:11:47 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 13:27:54 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *prev;
	t_list *last;

	prev = *begin_list;
	if (prev == NULL)
		return ;
	else if (prev->next == NULL)
		return ;
	*begin_list = (*begin_list)->next;
	last = (*begin_list)->next;
	prev->next = NULL;
	while (last)
	{
		(*begin_list)->next = prev;
		prev = (*begin_list);
		*begin_list = last;
		last = last->next;
	}
	(*begin_list)->next = prev;
}
