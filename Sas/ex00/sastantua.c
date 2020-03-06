/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:06:36 by tliao             #+#    #+#             */
/*   Updated: 2019/08/11 20:53:37 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_a[1000000000];

int		ft_putchar(char c);

void	ft_show(int lv, int last)
{
	int tmp;
	int i;

	i = 1;
	while (i <= lv)
	{
		tmp = ((g_a[last] - g_a[i]) / 2);
		while (tmp--)
		{
			ft_putchar(' ');
		}
		ft_putchar('/');
		tmp = g_a[i];
		while (tmp--)
		{
			ft_putchar('*');
		}
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
}

void	ft_door_2(int oddeven, int n, int i, int base)
{
	int k;
	int j;
	int tmp;

	k = 0;
	j = (n % 2 == 0) ? n - 1 : n;
	tmp = (g_a[base + i] - j) / 2;
	while (k++ < tmp)
		ft_putchar('*');
	k = 0;
	while (k++ < j)
	{
		if (j > 4)
		{
			if (i == oddeven + j / 2 && k == j - 1)
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		else
			ft_putchar('|');
	}
	k = 0;
	while (k++ < tmp)
		ft_putchar('*');
}

void	ft_door(int n, int base)
{
	int lv;
	int i;
	int tmp;
	int oddeven;

	lv = n + 2;
	i = 0;
	while (i < lv)
	{
		tmp = (g_a[base + lv - 1] - g_a[base + i]) / 2;
		while (tmp--)
			ft_putchar(' ');
		ft_putchar('/');
		oddeven = (n % 2) ? 2 : 3;
		if (i < oddeven)
		{
			while (g_a[base + i]--)
				ft_putchar('*');
		}
		else
			ft_door_2(oddeven, n, i, base);
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
}

void	sastantua(int size)
{
	int i;
	int j;
	int k;

	g_a[0] = -1;
	i = 1;
	j = 1;
	if (size == 0)
		return ;
	while (i <= size)
	{
		k = 1;
		if (i != 1)
			g_a[j] = i / 2 * 2 + 2;
		while (k <= i + 2)
		{
			g_a[j] += g_a[j - 1] + 2;
			j++;
			k++;
		}
		i++;
	}
	ft_show(j - i - 2, j - 1);
	ft_door(size, j - i - 1);
}
