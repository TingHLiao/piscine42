/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:58:10 by tliao             #+#    #+#             */
/*   Updated: 2019/08/13 12:59:43 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_show(unsigned int nbr, int len, char *base)
{
	if (nbr != 0)
	{
		ft_show(nbr / len, len, base);
		ft_putchar(base[nbr % len]);
	}
}

int		ft_valid(char *base, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32)
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				len;
	unsigned int	num;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (len <= 1)
		return ;
	if (!ft_valid(base, len))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		num = nbr * -1;
		ft_show(num, len, base);
	}
	else
		ft_show(nbr, len, base);
}
