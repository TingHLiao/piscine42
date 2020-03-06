/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:59:27 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 16:29:34 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int g_count;

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	t_list	*head;
	t_list	*last;
	void	*data;

	g_count = 1;
	i = 0;
	last = begin_list;
	while (last && g_count++)
		last = last->next;
	g_count--;
	head = begin_list;
	while (i++ < g_count / 2)
	{
		last = begin_list;
		j = 0;
		while (j++ < (g_count - i))
			last = last->next;
		data = head->data;
		head->data = last->data;
		last->data = data;
		head = head->next;
	}
}
