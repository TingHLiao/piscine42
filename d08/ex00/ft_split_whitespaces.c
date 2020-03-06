/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:48:06 by tliao             #+#    #+#             */
/*   Updated: 2019/08/15 22:23:08 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_len;
int g_flag;

int		ft_count(char *str, int i)
{
	int len;

	len = 0;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

int		ft_word(char *str)
{
	int i;
	int flag;
	int num;

	i = 0;
	num = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && flag)
		{
			num++;
			flag = 0;
		}
		else if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			flag = 1;
		i++;
	}
	return (num);
}

void	ft_spilt(int *k)
{
	*k += 1;
	g_flag = 1;
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = 0;
	k = 0;
	g_flag = 1;
	arr = malloc(sizeof(char*) * ft_word(str) + 1);
	while (str[k] != '\0')
	{
		j = 0;
		if (!(str[k] == ' ' || str[k] == '\n' || str[k] == '\t') && g_flag)
		{
			g_flag = 0;
			g_len = ft_count(str, k);
			arr[i++] = malloc(sizeof(char) * g_len);
			while (j < g_len)
				arr[i - 1][j++] = str[k++];
		}
		else if (str[k] == ' ' || str[k] == '\n' || str[k] == '\t')
			ft_spilt(&k);
	}
	arr[i] = 0;
	return (arr);
}
