/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:18:49 by tliao             #+#    #+#             */
/*   Updated: 2019/08/28 18:04:59 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_read_map(char *name)
{
	int		n;
	int		i;
	int		fd;
	char	c;

	fd = open(name, O_RDONLY);
	i = 0;
	while (read(fd, &c, 1) && c != '\n')
		continue ;
	while (i < g_line)
	{
		n = 0;
		g_int[i] = malloc(sizeof(int) * g_num);
		while (read(fd, &c, 1) && c != '\n' && (c == g_ch[0] || c == g_ch[1]))
			if (!ft_int(c, i, &n))
				break ;
		if (!ft_error(n, i, c))
			return (0);
		i++;
	}
	if (read(fd, &c, 1) != 0)
		return (0);
	return (1);
}

int		ft_read_line(char *name)
{
	int		fd;
	int		num;
	char	c;

	fd = open(name, O_RDONLY);
	num = 0;
	while (read(fd, &c, 1) && c != '\n')
		num++;
	close(fd);
	fd = open(name, O_RDONLY);
	while (num-- > 3 && read(fd, &c, 1))
		if (c >= '0' && c <= '9')
			g_line = g_line * 10 + (c - '0');
		else
			return (0);
	read(fd, g_ch, 3);
	g_int = malloc(sizeof(int*) * g_line);
	num = 0;
	read(fd, &c, 1);
	while (read(fd, &c, 1) && c != '\n')
		g_num++;
	close(fd);
	if (!ft_read_map(name))
		return (0);
	return (1);
}

void	ft_print(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_line)
	{
		j = 0;
		while (j < g_num)
		{
			if (i >= (g_loc[1] + 1 - g_loc[0]) && i <= g_loc[1]\
					&& j >= (g_loc[2] + 1 - g_loc[0]) && j <= g_loc[2])
				write(1, &g_ch[2], 1);
			else if (g_int[i][j] > 0)
				write(1, &g_ch[0], 1);
			else
				write(1, &g_ch[1], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	ft_input(void)
{
	char c;

	ft_init();
	if (!ft_stdin() || !ft_count_line() || !ft_count_num())
	{
		ft_free_list();
		while (read(STDIN_FILENO, &c, 1))
			continue ;
		write(1, "map error\n", 10);
	}
	else if (!g_loc[0])
	{
		while (read(STDIN_FILENO, &c, 1))
			continue ;
		ft_free(g_line - 1);
		write(1, "map error\n", 10);
	}
	else
	{
		ft_print();
		ft_free(g_line - 1);
		free(g_int);
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	while (i++ < (argc - 1) && argc > 1)
	{
		ft_init();
		if (!ft_read_line(argv[i]))
			write(1, "map error\n", 10);
		else if (!g_loc[0])
		{
			ft_free(g_line - 1);
			write(1, "map error\n", 10);
		}
		else
		{
			ft_print();
			ft_free(g_line - 1);
		}
		free(g_int);
		if (i != (argc - 1))
			write(1, "\n", 1);
	}
	if (argc == 1)
		ft_input();
	return (0);
}
