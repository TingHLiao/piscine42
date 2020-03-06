/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:05:31 by tliao             #+#    #+#             */
/*   Updated: 2019/08/10 14:50:43 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_q[10];

void	ft_putchar(char c);

void	ft_show(void)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ft_putchar(g_q[i++] + '1');
	}
	ft_putchar('\n');
}

int		ft_valid(int row, int col)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (g_q[i] == col)
			return (0);
		if ((g_q[i] - col == i - row) || (g_q[i] - col == row - i))
			return (0);
		i++;
	}
	return (1);
}

void	ft_place(int row)
{
	int j;

	if (row == 8)
	{
		ft_show();
	}
	else
	{
		j = 0;
		while (j < 8)
		{
			if (ft_valid(row, j))
			{
				g_q[row] = j;
				ft_place(row + 1);
			}
			j++;
		}
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	ft_place(0);
}
