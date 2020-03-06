/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:58:31 by tliao             #+#    #+#             */
/*   Updated: 2019/08/21 22:18:03 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str++, 1);
	}
}

void	ft_error(int err, char *str)
{
	if (err == 2)
	{
		write(1, "tail: ", 5);
		ft_putstr(str);
		write(1, ": No such file or directory\n", 28);
	}
}

void	ft_title(int i, char *str)
{
	if (i != 1)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	ft_putstr(str);
	write(1, " <==\n", 5);
}

int		ft_csize(int byte, int i, char **files, int flag)
{
	int		sum;
	int		fd;
	char	c;

	sum = 0;
	fd = open(files[i], O_RDWR);
	if (flag == 1)
	{
		while (read(fd, &c, 1))
			sum++;
		close(fd);
		return (sum - byte - 1);
	}
	else
	{
		while (read(fd, &c, 1))
			if (c == '\n')
				sum++;
		close(fd);
		return (sum - 10 - 1);
	}
}
