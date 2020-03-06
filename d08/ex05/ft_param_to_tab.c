/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:23:59 by tliao             #+#    #+#             */
/*   Updated: 2019/08/16 22:27:58 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char	**ft_split_whitespaces(char *str);

int		ft_count(int argc, char **argv)
{
	int i;
	int j;
	int sum;

	i = 0;
	sum = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			j++;
		sum = sum + j + 1;
		i++;
	}
	return (sum);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		sum;
	char	*str;

	sum = ft_count(argc, argv);
	if (sum == 0)
		return (0);
	str = malloc(sizeof(char) * sum);
	i = 0;
	j = 0;
	while (i < argc)
	{
		while (*(argv[i]) != '\0')
			str[j++] = *(argv[i])++;
		if (i != argc - 1)
			str[j++] = '\n';
		i++;
	}
	str[j] = '\0';
	return (str);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *par;
	char		**arr;
	
	par->size_param = ft_count(ac, av);
	par->copy = ft_concat_params(ac, av);
	arr = ft_split_whitespaces(par->copy);
	par->tab = arr;
	par->str = *arr;
	return (par);
}
