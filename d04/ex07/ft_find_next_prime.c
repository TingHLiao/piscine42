/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:26:55 by tliao             #+#    #+#             */
/*   Updated: 2019/08/10 19:23:33 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_prime(int nb)
{
	unsigned int i;

	i = 2;
	while (i * i <= (unsigned int)nb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 1)
		return (2);
	else
	{
		i = nb + 1;
		if (ft_prime(nb))
			return (nb);
		else
		{
			while (!ft_prime(i++))
				continue;
		}
	}
	return (i - 1);
}
