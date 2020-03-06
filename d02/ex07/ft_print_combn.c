/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:41:50 by tliao             #+#    #+#             */
/*   Updated: 2019/08/08 23:16:13 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**void	ft_putchar(char c)
**{
**	printf("%c",c);
**}
*/

void	ft_run(int *num, int lv, int n)
{
	int i[2];

	i[0] = num[lv];
	while (i[0] < 10)
	{
		num[lv] = i[0]++;
		if ((num[lv] > num[lv - 1]) && lv <= n)
		{
			ft_run(num, lv + 1, n);
		}
		if ((num[lv] > num[lv - 1]) && lv == n)
		{
			i[1] = 0;
			while (i[1] <= n)
			{
				ft_putchar(num[(i[1])++] + '0');
			}
			if (num[0] < 10 - n - 1)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		num[lv + 1] = num[lv];
	}
}

void	ft_single(void)
{
	int num;

	num = 0;
	while (num < 10)
	{
		if (num == 9)
			ft_putchar('9');
		else
		{
			ft_putchar(num + '0');
			ft_putchar(',');
			ft_putchar(' ');
		}
		num++;
	}
}

void	ft_print_combn(int n)
{
	int num[11];
	int i;
	int j;

	j = 0;
	num[0] = 0;
	if (n == 1)
	{
		ft_single();
	}
	while (num[0] < 10 - n)
	{
		i = 1;
		num[0] = j;
		while (i < n)
		{
			num[i] = i + j;
			i++;
		}
		ft_run(num, 1, n - 1);
		j++;
	}
}

/*
**int main(){
**	ft_print_combn(5);
**}
*/
