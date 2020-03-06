/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:12:48 by tliao             #+#    #+#             */
/*   Updated: 2019/08/21 17:18:17 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define SIZE 28672

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str++, 1);
	}
}

void	ft_putfile(int num, char **files)
{
	int		i;
	int		size;
	int		fd;
	char	buf[SIZE];

	i = 0;
	while (i++ < num)
	{
		if ((fd = open(files[i], O_RDWR)) < 0)
		{
			write(1, "cat: ", 5);
			ft_putstr(files[i]);
			if (errno == 2)
				write(1, ": No such file or directory\n", 28);
			else if (errno == 21)
				write(1, ": Is a directory\n", 17);
			continue ;
		}
		while ((size = read(fd, buf, SIZE)))
		{
			buf[size] = '\0';
			ft_putstr(buf);
		}
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	char c;

	if (argc == 1)
		while (read(STDIN_FILENO, &c, 1))
			write(1, &c, 1);
	else
		ft_putfile(argc - 1, argv);
	return (0);
}
