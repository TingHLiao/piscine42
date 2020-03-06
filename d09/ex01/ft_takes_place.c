/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 00:00:34 by tliao             #+#    #+#             */
/*   Updated: 2019/08/16 00:23:19 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_show(int hour)
{
	if (hour == 24 || hour < 12)
		printf("A.M.");
	else
		printf("P.M.");
}

void	ft_takes_place(int hour)
{
	int h1;
	int h2;

	h1 = (hour > 12) ? hour - 12 : hour;
	h2 = (hour + 1 > 12) ? hour - 11 : hour + 1;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 ", h1);
	ft_show(hour);
	printf(" AND %d.00 ", h2);
	ft_show(hour + 1);
	printf("\n");
}
