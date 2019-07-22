/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 09:48:22 by yait-el-          #+#    #+#             */
/*   Updated: 2019/07/21 09:48:52 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			if_safe(t_tetriminos *tetris, t_map *map, int x, int y)
{
	if ((x + tetris->x[0]) < 0 || (y + tetris->y[0]) < 0)
		return (1);
	if ((x + tetris->x[1]) < 0 || (y + tetris->y[1]) < 0)
		return (1);
	if ((x + tetris->x[2]) < 0 || (y + tetris->y[2]) < 0)
		return (1);
	if ((x + tetris->x[3]) < 0 || (y + tetris->y[3]) < 0)
		return (1);
	if ((x + tetris->x[0]) > (map->x_map - 1) ||
			(y + tetris->y[0]) > (map->y_map - 1))
		return (1);
	if ((x + tetris->x[1]) > (map->x_map - 1) ||
			(y + tetris->y[1]) > (map->y_map - 1))
		return (1);
	if ((x + tetris->x[2]) > map->x_map - 1 ||
			(y + tetris->y[2]) > (map->y_map - 1))
		return (1);
	if ((x + tetris->x[3]) > (map->x_map - 1) ||
			(y + tetris->y[3]) > (map->y_map - 1))
		return (1);
	return (0);
}

int			if_empty(t_tetriminos *tetris, t_map *map, int x, int y)
{
	if (map->map_2d[x + (tetris)->x[0]][y + (tetris)->y[0]] != '.')
		return (1);
	if (map->map_2d[x + (tetris)->x[1]][y + (tetris)->y[1]] != '.')
		return (1);
	if (map->map_2d[x + (tetris)->x[2]][y + (tetris)->y[2]] != '.')
		return (1);
	if (map->map_2d[x + (tetris)->x[3]][y + (tetris)->y[3]] != '.')
		return (1);
	return (0);
}

int			ft_put_tet(t_tetriminos *tetris, t_map *map, int x, int y)
{
	if (if_safe(tetris, map, x, y))
		return (0);
	if (if_empty(tetris, map, x, y))
		return (0);
	map->map_2d[x + (tetris)->x[0]][y + (tetris)->y[0]] = (tetris)->c;
	map->map_2d[x + (tetris)->x[1]][y + (tetris)->y[1]] = (tetris)->c;
	map->map_2d[x + (tetris)->x[2]][y + (tetris)->y[2]] = (tetris)->c;
	map->map_2d[x + (tetris)->x[3]][y + (tetris)->y[3]] = (tetris)->c;
	return (1);
}

void		ft_remove_tet(t_tetriminos *tetris, t_map *map, int x, int y)
{
	map->map_2d[x + tetris->x[0]][y + tetris->y[0]] = '.';
	map->map_2d[x + tetris->x[1]][y + tetris->y[1]] = '.';
	map->map_2d[x + tetris->x[2]][y + tetris->y[2]] = '.';
	map->map_2d[x + tetris->x[3]][y + tetris->y[3]] = '.';
}

int			backtraking(t_range *range, t_map *map, int i)
{
	int		x;
	int		y;

	if (i == range->count)
		return (1);
	x = 0;
	while (x < map->x_map)
	{
		y = 0;
		while (y < map->y_map)
		{
			if (ft_put_tet(&(range->all[i]), map, x, y))
			{
				if (backtraking(range, map, i + 1))
					return (1);
				else
					ft_remove_tet(&(range->all[i]), map, x, y);
			}
			y++;
		}
		x++;
	}
	return (0);
}
