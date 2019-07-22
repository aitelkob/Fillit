/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <sberrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:56:07 by sberrich          #+#    #+#             */
/*   Updated: 2019/07/22 04:24:59 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int				check_count(char *str)
{
	int		point;
	int		i;
	int		hash;

	point = 0;
	i = 0;
	hash = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hash++;
		if (str[i] == '.')
			point++;
		i++;
	}
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' ||
			str[19] != '\n' || (str[20] != '\n' && str[20]))
		return (0);
	if (hash == 4 && point == 12)
		return (1);
	return (0);
}

int				check_connection(char *str)
{
	int		i;
	int		connection;

	connection = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i >= 1 && str[i - 1] == '#')
				connection++;
			if (i < 19 && str[i + 1] == '#')
				connection++;
			if (i >= 5 && str[i - 5] == '#')
				connection++;
			if (i < 14 && str[i + 5] == '#')
				connection++;
		}
		i++;
	}
	if (connection >= 6)
		return (1);
	return (0);
}

t_tetriminos	*stock_tetris(char *buff)
{
	t_tetriminos	*tetros;
	int				i;
	int				j;
	int				k;
	int				h;

	k = 0;
	i = -1;
	h = -1;
	if (!(tetros = (t_tetriminos *)malloc(sizeof(t_tetriminos))))
		ft_exit();
	while (++i < 19)
	{
		j = -1;
		while (++j < 4)
			if (buff[i++] == '#')
			{
				tetros->x[++h] = k;
				tetros->y[h] = j;
			}
		k++;
	}
	drag(tetros);
	return (tetros);
}

int				checker(char *buff, int ret)
{
	if (ret < 20)
		return (0);
	if (!check_count(buff) || !check_connection(buff))
		return (0);
	return (1);
}

int				ft_reader(int fd, t_range *range)
{
	char			buff[22];
	int				ret;
	int				i;
	t_tetriminos	*tetriminos;

	i = 0;
	while (((ret = read(fd, buff, 21)) > 0))
	{
		buff[ret] = '\0';
		if (!checker(buff, ret))
			return (0);
		tetriminos = stock_tetris(buff);
		tetriminos->c = 'A' + i;
		if (i < 26)
		{
			range->all[i] = *tetriminos;
			free(tetriminos);
		}
		if (ret == 20)
			break ;
		i++;
	}
	range->count = i + 1;
	return (ret == 20);
}
