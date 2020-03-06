/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:54:25 by tliao             #+#    #+#             */
/*   Updated: 2019/08/28 18:05:31 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_second_line(void)
{
	char	c;
	int		n;
	t_list	*p;

	n = 0;
	while (g_head)
	{
		c = g_head->c;
		if (c != g_ch[0] && c != g_ch[1])
			return (0);
		else
			ft_int(c, 0, &n);
		p = g_head;
		g_head = g_head->next;
		free(p);
	}
	return (1);
}

int		ft_count_map(void)
{
	int		i;
	int		n;
	char	c;

	i = 0;
	while (i < g_line)
	{
		n = 0;
		g_int[i] = malloc(sizeof(int) * g_num);
		if (i == 0 && !ft_second_line())
			return (0);
		else if (i != 0)
		{
			while (read(STDIN_FILENO, &c, 1) && c != '\n' &&\
					(c == g_ch[0] || c == g_ch[1]))
				if (!ft_int(c, i, &n))
					break ;
			if (!ft_error(n, i, c))
				return (0);
		}
		i++;
	}
	if (read(STDIN_FILENO, &c, 1) != 0)
		return (0);
	return (1);
}

int		ft_count_num(void)
{
	char	c;
	t_list	*p;
	t_list	*q;

	g_num = 0;
	g_head = NULL;
	while (read(STDIN_FILENO, &c, 1) && c != '\n')
	{
		if (!g_head)
		{
			g_head = ft_create(c);
			q = g_head;
		}
		else
		{
			p = ft_create(c);
			q->next = p;
			q = p;
		}
		g_num++;
	}
	if (c != '\n' || !ft_count_map())
		return (0);
	return (1);
}

int		ft_count_line(void)
{
	t_list	*p;
	int		i;

	while (g_num-- > 3)
	{
		if (g_head->c >= '0' && g_head->c <= '9')
			g_line = g_line * 10 + (g_head->c - '0');
		else
			return (0);
		p = g_head;
		g_head = g_head->next;
		free(p);
	}
	i = 0;
	while (i < 3)
	{
		g_ch[i++] = g_head->c;
		p = g_head;
		g_head = g_head->next;
		free(p);
	}
	g_int = malloc(sizeof(int*) * g_line);
	return (1);
}

int		ft_stdin(void)
{
	char	c;
	t_list	*p;
	t_list	*q;

	g_head = NULL;
	while (read(STDIN_FILENO, &c, 1) && c != '\n')
	{
		if (!g_head)
		{
			g_head = ft_create(c);
			q = g_head;
		}
		else
		{
			p = ft_create(c);
			q->next = p;
			q = p;
		}
		g_num++;
	}
	if (c != '\n')
		return (0);
	return (1);
}
