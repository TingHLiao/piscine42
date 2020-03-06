/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:15:41 by tliao             #+#    #+#             */
/*   Updated: 2019/08/13 19:39:13 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_show(int *arr, unsigned char *s, unsigned int i)
{
	unsigned int	j;
	int				n;
	char			*base;

	base = "0123456789abcdef";
	n = 7;
	while (n >= 0)
		ft_putchar(base[arr[n--]]);
	ft_putchar(':');
	ft_putchar(' ');
	j = 16 * i;
	while (j < 16 * (i + 1))
	{
		ft_putchar(base[s[j] / 16 % 16]);
		ft_putchar(base[s[j] % 16]);
		if (j++ % 2)
			ft_putchar(' ');
	}
	ft_putchar(' ');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				num[10];
	int				n;
	unsigned int	i;
	unsigned int	j;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)addr;
	while (i < size)
	{
		j = 0;
		n = 16 * i;
		while (j < 8)
		{
			num[j++] = n % 16;
			n /= 16;
		}
		ft_show(num, s, i);
		j = i * 16;
		while (j++ < 16 * (i + 1))
			ft_putchar((s[j - 1] > 31 && s[j - 1] < 127) ? s[j - 1] : '.');
		ft_putchar('\n');
		i++;
	}
	return (addr);
}
