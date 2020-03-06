/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:24:32 by tliao             #+#    #+#             */
/*   Updated: 2019/08/15 20:07:56 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int				*arr;
	unsigned int	i;

	if (min >= max)
		return (0);
	i = 0;
	arr = malloc(sizeof(int) * (max - min));
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
