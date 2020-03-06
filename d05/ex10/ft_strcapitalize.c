/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:31:05 by tliao             #+#    #+#             */
/*   Updated: 2019/08/12 17:55:02 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_word(char *c)
{
	int flag;

	flag = 0;
	if (*c >= '0' && *c <= '9')
		flag = 1;
	if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
		flag = 1;
	if (flag)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		flag;
	char	*c;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		c = &str[i++];
		if (ft_is_word(c))
		{
			if (!flag)
			{
				if (*c >= 'a' && *c <= 'z')
					*c -= 'a' - 'A';
				flag = 1;
			}
			else if (flag)
				if (*c >= 'A' && *c <= 'Z')
					*c += 'a' - 'A';
		}
		else
			flag = 0;
	}
	return (str);
}
