/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:32:23 by tliao             #+#    #+#             */
/*   Updated: 2019/08/20 11:42:51 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*t;
	t_list	*head;

	head = NULL;
	i = 0;
	while (i < ac)
	{
		t = ft_create_elem(av[i]);
		t->next = head;
		head = t;
		i++;
	}
	return (head);
}
