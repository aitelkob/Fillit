/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_holder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <sberrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 04:33:00 by yait-el-          #+#    #+#             */
/*   Updated: 2019/07/22 03:10:28 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char		**ft_jedida_map_2d(int x, int y)
{
	char	**map_str;
	int		j;
	int		i;

	i = 0;
	map_str = (char **)malloc(sizeof(char*) * (x + 1));
	while (i < x)
	{
		j = 0;
		map_str[i] = (char *)malloc(sizeof(char*) * (y + 1));
		while (j < y)
		{
			map_str[i][j] = '.';
			j++;
		}
		map_str[i][j] = '\0';
		i++;
	}
	map_str[i] = NULL;
	return (map_str);
}

int			ft_start_size_map(t_range *range)
{
	int		size;
	int		area;

	size = 2;
	area = ((range->count) * 4);
	while ((size * size) < area)
		size++;
	return (size);
}

void		ft_free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->x_map)
	{
		free(map->map_2d[i]);
		i++;
	}
	free(map->map_2d);
	free(map);
}

t_map		*ft_re_size_map(t_map *old)
{
	int		x;
	int		y;
	t_map	*map;

	x = old->x_map + 1;
	y = old->y_map + 1;
	ft_free_map(old);
	map = (t_map*)malloc(sizeof(t_map));
	map->map_2d = ft_jedida_map_2d(x, y);
	map->x_map = x;
	map->y_map = y;
	return (map);
}

t_map		*ft_create_map(t_range range)
{
	int		x;
	int		y;
	t_map	*map;

	x = ft_start_size_map(&range);
	y = x;
	map = (t_map*)malloc(sizeof(t_map));
	map->map_2d = ft_jedida_map_2d(x, y);
	map->x_map = x;
	map->y_map = y;
	return (map);
}
