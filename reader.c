/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 04:44:25 by yait-el-          #+#    #+#             */
/*   Updated: 2019/06/04 10:12:24 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

typedef struct	s_valid
{
	int     hash;
	int     point;
	int     line;
	int     connection;
}				t_valid;

int		check_char(char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		if (str[i] != '#' && str[i] != '\n' && str[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

int     check_connection(char *str,int i)
{
	int     connection;

	connection = 0;
	if (str[i - 1] == '#')
		connection++;
	if (str[i + 1] == '#')
		connection++;
	if (str[i + 5] == '#')
		connection++;
	if (str[i - 5] == '#')
		connection++;
	return (connection);
}

t_valid		*char_counter(char *str)
{
	t_valid		*count;
	int			i;

	count= (*t_valid)malloc(sizeof(t_valid));
	count->hash = 0;
	count->point = 0;
	count->line = 0;
	count->connection = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			count->hash++;
		if (str[i] == '.')
			count->point++;
		if (str[i] == '\n')
			count->line++;
		i++;
	}
	return (count);
}

int		checker(t_valid *count)
{
	if (count->hash != 4 || count->hash != 8)
		return (1);
	if ((count->line +1) % 5 != 0)
		return (1);
	return (0);
}

int		char_counter(char *str)
{
	int		i;
	int		hash;
	int		point;
	int		line;
	int		connection;

	connection = 0;
	point = 0;
	i = 0;
	hash = 0;
	line = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			connection += check_connection(str,i);
			hash++;
		}
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			line++;
		i++;
	}
	if (hash != 4 && (line != 5 || line != 4 ) && point != 16 && (connection != 6 || connection != 8))
		return (1);
	return (0);
}

int		all_chekers(char *str)
{
	if (check_char(str))
		return (1);
	if (char_counter(str))
		return (1);
	return (0);
}
char	*extract(char *str,size_t size)
{
	char *tmp;
	size_t  sizet;

	tmp = (char*)malloc(sizeof(char) * size);
	sizet = ft_strlen(str);
	ft_memcpy(tmp,str,sizet);
	free(str);
	return (tmp);
}

char	*ft_readfile(char *file)
{
	int		fd;
	int		ret;
	char	*buff;
	char	*tetrominos;
	size_t 	size;
	char	*tmp;


	size = 22;	
	fd  = open(file,O_RDONLY);
	buff = ft_strnew(21);
	tetrominos= ft_strnew(21);
	while ((ret = read(fd,buff,21)))
	{
		ft_strcat(tetrominos,buff);
		size = size + 21;
		tetrominos = extract(tetrominos,size);
		ft_memset(tmp,0,size);
	}
	if (all_chekers(tetrominos))
	{
		ft_putendl("the char is not valid");
		exit(0);
	}
	return (tetrominos);
}
int main(int argc,char **argv)
{
	char	*str;

	str = ft_readfile(argv[1]);
}
