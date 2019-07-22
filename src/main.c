/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <sberrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:58:03 by sberrich          #+#    #+#             */
/*   Updated: 2019/07/22 04:25:24 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	t_map		*d;
	t_range		range;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_putendl("error ");
	if (!argv[1])
		ft_putendl("Usage : Fillit ource_f le target_file ");
	if (ft_reader(fd, &range))
	{
		d = solver(&range);
		ft_print_solution(d->map_2d);
		ft_free_map(d);
	}
	else
		ft_putendl("error");
	return (0);
}
