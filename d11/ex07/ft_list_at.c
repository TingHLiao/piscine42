/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:51:53 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 13:09:55 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*p;
	int		n;

	n = nbr;
	p = begin_list;
	while (n-- > 0)
	{
		if (!p)
			return (NULL);
		p = p->next;
	}
	return (p);
}
