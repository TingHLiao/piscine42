/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:55:50 by tliao             #+#    #+#             */
/*   Updated: 2019/08/08 23:23:54 by tliao            ###   ########.fr       */
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

void	ft_putnbr(int nb)
{
	int nbtmp;
	int count;
	int string[32];

	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	nbtmp = nb;
	count = 0;
	while (nbtmp / 10 != 0)
	{
		string[count++] = nbtmp % 10;
		nbtmp /= 10;
	}
	string[count] = nbtmp;
	while (count >= 0)
	{
		ft_putchar(string[count--] + '0');
	}
}

/*
**int main(){
**	ft_putnbr(-24);
**	return (0);
**}
*/
