/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:51:15 by tliao             #+#    #+#             */
/*   Updated: 2019/08/15 20:33:11 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count(int argc, char **argv)
{
	int i;
	int j;
	int sum;

	i = 1;
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
	i = 1;
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
