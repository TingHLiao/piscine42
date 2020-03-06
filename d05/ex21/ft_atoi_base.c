/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:10:03 by tliao             #+#    #+#             */
/*   Updated: 2019/08/13 12:57:09 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_minus;
int g_len;

unsigned int	ft_cal(char *str, char *base)
{
	int				i;
	int				index;
	int				bas;
	int				count;
	unsigned int	sum;

	i = 0;
	sum = 0;
	count = 0;
	bas = 1;
	while (str[count] != '\0')
		count++;
	while (count-- > 0)
	{
		i = 0;
		while (i < g_len)
		{
			index = (base[i] == str[count]) ? i : index;
			i++;
		}
		sum += index * bas;
		bas *= g_len;
	}
	return (sum);
}

void			ft_atoi2(char *str, char *base)
{
	int flag;
	int i;

	while (*str != '\0')
	{
		flag = 0;
		i = 0;
		while (i < g_len)
		{
			if (*str == base[i])
				flag = 1;
			i++;
		}
		if (!flag)
		{
			*str = '\0';
			break ;
		}
		str++;
	}
}

char			*ft_atoi(char *str, char *base)
{
	int		num;
	char	*ans;

	g_minus = 1;
	num = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		g_minus = -1;
		str++;
	}
	if (*str == '+' && g_minus == 1)
		str++;
	ans = str;
	ft_atoi2(str, base);
	return (ans);
}

int				ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int sum;

	i = 0;
	while (base[g_len] != '\0')
		g_len++;
	if (g_len == 1)
		return (0);
	while (i < g_len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32)
			return (0);
		j = i + 1;
		while (j < g_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	str = ft_atoi(str, base);
	sum = g_minus * ft_cal(str, base);
	return (sum);
}
