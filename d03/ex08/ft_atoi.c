/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:19:31 by tliao             #+#    #+#             */
/*   Updated: 2019/08/09 15:36:39 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int num;
	int flag_minus;

	num = 0;
	flag_minus = 0;
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;
		if (*str == '-')
		{
			flag_minus = 1;
			str++;
		}
		if (*str == '+' && !flag_minus)
			str++;
		while (!(*str < '0' || *str > '9'))
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		num = (flag_minus) ? num *= -1 : num;
		return (num);
	}
	return (num);
}
