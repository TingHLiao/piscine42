/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:36:50 by tliao             #+#    #+#             */
/*   Updated: 2019/08/17 21:58:55 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	if (*s1 != '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2));
	if (*s1 == '\0' && *s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}
