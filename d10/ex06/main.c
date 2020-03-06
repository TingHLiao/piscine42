/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:24:30 by tliao             #+#    #+#             */
/*   Updated: 2019/08/19 21:11:29 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_sum(int x, int y);
int		ft_sub(int x, int y);
int		ft_mul(int x, int y);
int		ft_div(int x, int y);
int		ft_mod(int x, int y);

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
	int	(*f[5])(int, int);

	f[0] = &ft_sum;
	f[1] = &ft_sub;
	f[2] = &ft_mul;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	if (op == '+')
		return ((*f[0])(v1, v2));
	else if (op == '-')
		return ((*f[1])(v1, v2));
	else if (op == '*')
		return ((*f[2])(v1, v2));
	else if (op == '/')
		return ((*f[3])(v1, v2));
	else if (op == '%')
		return ((*f[4])(v1, v2));
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int		v1;
	int		v2;

	if (argc == 4)
	{
		if (*(argv[2] + 1) != '\0')
		{
			write(1, "0\n", 2);
			return (0);
		}
		v1 = ft_atoi(argv[1]);
		v2 = ft_atoi(argv[3]);
		if (*argv[2] == '/' && v2 == 0)
			write(1, "Stop : division by zero", 23);
		else if (*argv[2] == '%' && v2 == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(ft_cal(v1, v2, *argv[2]));
		write(1, "\n", 1);
	}
	return (0);
}
