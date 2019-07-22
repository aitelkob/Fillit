/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <sberrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 03:20:32 by yait-el-          #+#    #+#             */
/*   Updated: 2019/07/21 02:14:52 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void		drag(t_tetriminos *tetriminos)
{
	int		i;
	int		x;
	int		y;

	i = 1;
	x = tetriminos->x[0];
	y = tetriminos->y[0];
	while (i < 4)
	{
		if (tetriminos->x[i] < x)
			x = tetriminos->x[i];
		if (tetriminos->y[i] < y)
			y = tetriminos->y[i];
		i++;
	}
	while (--i >= 0)
	{
		tetriminos->x[i] -= x;
		tetriminos->y[i] -= y;
	}
}
