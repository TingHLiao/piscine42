/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:50:59 by tliao             #+#    #+#             */
/*   Updated: 2019/08/09 15:40:11 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tab[j] = tab[j] + tab[j + 1];
				tab[j + 1] = tab[j] - tab[j + 1];
				tab[j] = tab[j] - tab[j + 1];
			}
			j++;
		}
		i++;
	}
}
