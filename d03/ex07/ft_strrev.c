/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:16:17 by tliao             #+#    #+#             */
/*   Updated: 2019/08/09 15:36:32 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	c;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	while (i < count)
	{
		count--;
		c = str[i];
		str[i] = str[count];
		str[count] = c;
		i++;
	}
	return (str);
}
