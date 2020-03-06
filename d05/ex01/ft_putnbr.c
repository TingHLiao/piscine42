/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:21:41 by tliao             #+#    #+#             */
/*   Updated: 2019/08/12 20:27:24 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

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
