/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:00:49 by tliao             #+#    #+#             */
/*   Updated: 2019/08/28 12:51:36 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_free_list(void)
{
	t_list *p;

	while (g_head)
	{
		p = g_head;
		g_head = g_head->next;
		free(p);
	}
}

void	ft_free(int len)
{
	int i;

	i = 0;
	while (i <= len)
		free(g_int[i++]);
}
