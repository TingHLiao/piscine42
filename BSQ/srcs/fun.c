/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:02:53 by tliao             #+#    #+#             */
/*   Updated: 2019/08/28 12:42:53 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init(void)
{
	g_loc[0] = 0;
	g_line = 0;
	g_num = 0;
}

int		ft_min(int i, int j)
{
	int min;

	if (i == 0 || j == 0)
		return (1);
	min = g_int[i][j - 1];
	if (min > g_int[i - 1][j - 1])
		min = g_int[i - 1][j - 1];
	if (min > g_int[i - 1][j])
		min = g_int[i - 1][j];
	return (min + 1);
}

int		ft_int(char c, int i, int *n)
{
	if (*n > g_num)
		return (0);
	(*n)++;
	if (c == g_ch[1])
		g_int[i][*n - 1] = 0;
	else
	{
		g_int[i][*n - 1] = ft_min(i, *n - 1);
		if (g_int[i][*n - 1] > g_loc[0])
		{
			g_loc[0] = g_int[i][*n - 1];
			g_loc[1] = i;
			g_loc[2] = *n - 1;
		}
	}
	return (1);
}

int		ft_error(int n, int i, char c)
{
	if (c != '\n' || n != g_num)
	{
		ft_free(i);
		return (0);
	}
	return (1);
}

t_list	*ft_create(char c)
{
	t_list *p;

	p = malloc(sizeof(t_list));
	p->c = c;
	p->next = NULL;
	return (p);
}
