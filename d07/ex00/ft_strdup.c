/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:06:49 by tliao             #+#    #+#             */
/*   Updated: 2019/08/15 20:07:05 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (i == 0)
		return (0);
	str = malloc(sizeof(char) * i);
	i = 0;
	while (src[i++] != '\0')
		str[i - 1] = src[i - 1];
	str[i] = '\0';
	return (str);
}
