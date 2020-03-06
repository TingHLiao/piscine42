/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:18:58 by tliao             #+#    #+#             */
/*   Updated: 2019/08/21 22:15:48 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int		g_size;
int		g_byte;

void	ft_putstr(char *str);
void	ft_error(int err, char *files);
void	ft_title(int i, char *str);
int		ft_csize(int byte, int i, char **files, int flag);

int		ft_byte(char *str)
{
	int flag;

	g_byte = 0;
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			flag = (*str == '-') ? 1 : 2;
			str++;
		}
		else
			flag = 1;
		while (*str >= '0' && *str <= '9')
		{
			g_byte = g_byte * 10 + (*str - '0');
			str++;
		}
		if (*str != '\0')
			return (-1);
	}
	return (flag);
}

void	ft_putbyte(int num, char **files)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	while (i++ < num)
	{
		if ((fd = open(files[i + 2], O_RDWR)) < 0)
		{
			if (errno == 21)
				ft_title(i, files[i + 2]);
			ft_error(errno, files[i + 2]);
			close(fd);
			continue ;
		}
		if (num > 1)
			ft_title(i, files[i + 2]);
		g_size = ft_csize(g_byte, i + 2, files, 1);
		while (g_size >= 0 && read(fd, &c, 1))
			g_size--;
		while (read(fd, &c, 1))
			write(1, &c, 1);
		close(fd);
	}
}

void	ft_skip(int num, char **files)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	while (i++ < num)
	{
		if ((fd = open(files[i + 2], O_RDWR)) < 0)
		{
			if (errno == 21)
				ft_title(i, files[i + 2]);
			ft_error(errno, files[i + 2]);
			close(fd);
			continue ;
		}
		if (num > 1)
			ft_title(i, files[i + 2]);
		g_size = g_byte;
		while (g_size >= 0 && read(fd, &c, 1))
			g_size--;
		while (read(fd, &c, 1))
			write(1, &c, 1);
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	int flag;

	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
	{
		flag = ft_byte(argv[2]);
		if (flag == -1)
		{
			write(1, "tail: illegal offset -- ", 25);
			ft_putstr(argv[2]);
			write(1, "\n", 1);
			return (0);
		}
		else if (flag == 1)
			ft_putbyte(argc - 3, argv);
		else
		{
			g_byte -= 2;
			ft_skip(argc - 3, argv);
		}
	}
	return (0);
}
