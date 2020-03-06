/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:53:51 by tliao             #+#    #+#             */
/*   Updated: 2019/08/10 16:23:43 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c);

void	ft_show(int i, int j, int wid, int len)
{
	if (i == 1 || i == len)
	{
		if (j == 1 || j == wid)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else if (i > 1 && i < len)
	{
		if (j == 1 || j == wid)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int wid, int len)
{
	int i;
	int j;

	i = 0;
	while (i++ < len)
	{
		j = 0;
		while (j++ < wid)
		{
			ft_show(i, j, wid, len);
		}
		ft_putchar('\n');
	}
}
