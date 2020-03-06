/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:20:25 by tliao             #+#    #+#             */
/*   Updated: 2019/08/10 14:51:16 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_count;
int g_q[10];

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
		g_count++;
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

int		ft_eight_queens_puzzle(void)
{
	ft_place(0);
	return (g_count);
}
