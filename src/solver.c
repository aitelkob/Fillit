/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 09:49:11 by yait-el-          #+#    #+#             */
/*   Updated: 2019/07/22 00:20:21 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_map	*solver(t_range *range)
{
	t_map *map;

	map = ft_create_map(*range);
	while (!backtraking(range, map, 0))
	{
		map = ft_re_size_map(map);
	}
	return (map);
}
