/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:20:48 by tliao             #+#    #+#             */
/*   Updated: 2019/08/28 14:16:50 by tliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	char			c;
	struct s_list	*next;
}					t_list;

int					**g_int;
int					g_line;
int					g_num;
int					g_first;
int					g_loc[3];
char				g_ch[3];
t_list				*g_head;

void				ft_free(int len);
void				ft_free_list(void);
void				ft_init(void);
int					ft_int(char c, int i, int *n);
int					ft_error(int n, int i, char c);
int					ft_min(int i, int j);
t_list				*ft_create(char c);
int					ft_read_map(char *name);
int					ft_read_line(char *name);
void				ft_print(void);
void				ft_input(void);
int					ft_stdin(void);
int					ft_count_line(void);
int					ft_count_num(void);
int					ft_second_line(void);
int					ft_count_map(void);

#endif
