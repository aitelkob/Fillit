/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 03:37:31 by yait-el-          #+#    #+#             */
/*   Updated: 2019/05/30 04:53:49 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"

int main(int argc, char **argv)
{
	int fd = open(argv[1],O_RDONLY);
	char *line;

	while (get_next_line(fd,&line))
	{
		ft_putendl(line);
	}
	return (0);
}
