/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:45:31 by tliao             #+#    #+#             */
/*   Updated: 2019/08/13 20:25:40 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_count(char *dest, char *src, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	if (size < i)
		i = size;
	while (src[j] != '\0')
		j++;
	return (i + j);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int num;

	num = ft_count(dest, src, size);
	while (*dest != '\0' && size--)
		dest++;
	if (!size)
		return (num);
	size--;
	while (*src != '\0' && size--)
	{
		*(dest++) = *(src++);
	}
	*dest = '\0';
	return (num);
}
