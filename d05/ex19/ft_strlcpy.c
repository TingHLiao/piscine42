/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:15:24 by tliao             #+#    #+#             */
/*   Updated: 2019/08/13 20:33:02 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int sum;

	sum = 0;
	while (src[sum] != '\0')
		sum++;
	i = 0;
	while (src[i] != '\0' && size--)
	{
		if (!size)
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (sum);
}
