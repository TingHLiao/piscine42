/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:43:31 by tliao             #+#    #+#             */
/*   Updated: 2019/08/08 21:31:19 by tliao            ###   ########.fr       */
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

void	ft_show(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int num[4];

	num[0] = '0';
	while (num[0] < '8')
	{
		num[1] = num[0] + 1;
		while (num[1] < '9')
		{
			num[2] = num[1] + 1;
			while (num[2] <= '9')
			{
				show(num[0], num[1], num[2]);
				num[2]++;
			}
			num[1]++;
		}
		num[0]++;
	}
}

/*
**int main(){
**	ft_print_comb();
**	return (0);
**}
*/
