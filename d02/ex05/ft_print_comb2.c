/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:51:28 by tliao             #+#    #+#             */
/*   Updated: 2019/08/08 21:32:07 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**int		ft_putchar(char c)
**{
**	write(1, &c, 1);
**	return 0;
**}
*/

void	ft_show(int x, int y)
{
	ft_putchar(x / 10 + '0');
	ft_putchar(x % 10 + '0');
	ft_putchar(' ');
	ft_putchar(y / 10 + '0');
	ft_putchar(y % 10 + '0');
	if (!(x == 98 && y == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int num1;
	int num2;

	num1 = 0;
	while (num1 < 100)
	{
		num2 = num1 + 1;
		while (num2 < 100)
		{
			show(num1, num2);
			num2++;
		}
		num1++;
	}
}

/*
**int main(){
**	ft_print_comb2();
**	return (0);
**}
*/
