/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:30:02 by tliao             #+#    #+#             */
/*   Updated: 2019/08/08 10:33:22 by tliao            ###   ########.fr       */
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

void	ft_print_reverse_alphabet(void)
{
	int i;

	i = 0;
	while (i < 26)
	{
		ft_putchar('z' - i);
		i++;
	}
}
