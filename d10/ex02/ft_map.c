/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:48:43 by tliao             #+#    #+#             */
/*   Updated: 2019/08/19 14:59:48 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *arr;
	int i;

	i = 0;
	arr = malloc(sizeof(int) * length);
	while (i++ < length)
		arr[i - 1] = f(tab[i - 1]);
	return (arr);
}
