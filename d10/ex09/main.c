/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:24:30 by tliao             #+#    #+#             */
/*   Updated: 2019/08/19 22:37:14 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_struct.h"
#include "ft_opp.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbtmp;
	int				count;
	int				string[32];

	if (nb < 0)
	{
		nbtmp = nb * (-1);
		ft_putchar('-');
	}
	else
		nbtmp = nb;
	count = 0;
	while (nbtmp / 10 != 0)
	{
		string[count++] = nbtmp % 10;
		nbtmp /= 10;
	}
	string[count] = nbtmp;
	while (count >= 0)
		ft_putchar(string[count--] + '0');
}

int		ft_atoi(char *str)
{
	int				flag_minus;
	unsigned int	num;

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
		return ((flag_minus) ? num * -1 : num);
	}
	return (num);
}

int		ft_cal(int v1, int v2, char op)
{
	int i;

	if (op == '-' || op == '+' || op == '*' || op == '/' || op == '%')
	{
		i = 0;
		while (i < 5)
		{
			if (op == *g_opptab[i].op)
				return (g_opptab[i].f(v1, v2));
			i++;
		}
		return (0);
	}
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int		v1;
	int		v2;
	char	op;

	if (argc == 4)
	{
		if (*(argv[2] + 1) != '\0')
		{
			write(1, "0\n", 2);
			return (0);
		}
		op = *argv[2];
		v1 = ft_atoi(argv[1]);
		v2 = ft_atoi(argv[3]);
		if (op == '/' && v2 == 0)
			write(1, "Stop : division by zero", 23);
		else if (op == '%' && v2 == 0)
			write(1, "Stop : modulo by zero", 21);
		else if (op == '-' || op == '+' || op == '*' || op == '/' || op == '%')
			ft_putnbr(ft_cal(v1, v2, *argv[2]));
		else
			write(1, "error : only [ + - * / % ] are accepted.", 40);
		write(1, "\n", 1);
	}
	return (0);
}
