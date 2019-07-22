/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <sberrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:49:33 by sberrich          #+#    #+#             */
/*   Updated: 2019/07/21 23:58:03 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include "fcntl.h"
# include <stdio.h>

typedef struct		s_tetriminos
{
	int				x[4];
	int				y[4];
	char			c;
}					t_tetriminos;

typedef struct		s_range
{
	t_tetriminos	all[26];
	int				count;
}					t_range;

typedef struct		s_map
{
	char			**map_2d;
	int				x_map;
	int				y_map;
}					t_map;

void				drag(t_tetriminos *tetriminos);
int					ft_reader(int fd, t_range *range);
int					check_count(char *str);
int					check_connection(char *str);
void				ft_exit();
char				**ft_jedida_map_2d(int x, int y);
int					ft_start_size_map(t_range *range);
void				ft_free_map(t_map *map);
t_map				*ft_re_size_map(t_map *old);
t_map				*ft_create_map(t_range range);
t_map				*solver(t_range *range);
int					backtraking(t_range *range, t_map *map, int i);
void				ft_remove_tet(t_tetriminos *tetris,
		t_map *maps, int x, int y);
int					ft_put_tet(t_tetriminos *tetris, t_map *map, int x, int y);
int					if_empty(t_tetriminos *tetris, t_map *map, int x, int y);
int					if_safe(t_tetriminos *tetris, t_map *map, int x, int y);
void				ft_print_solution(char **str);

#endif
