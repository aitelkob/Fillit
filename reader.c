/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 04:44:25 by yait-el-          #+#    #+#             */
/*   Updated: 2019/06/10 11:03:53 by yait-el-         ###   ########.fr       */
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

	count = (t_valid*)malloc(sizeof(t_valid));
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
	if (count->hash < 4)
		return (1);
	if ( (count->hash % 4) != 0 ||((count->line +1) % 5 != 0) 
			|| ((count->point % 4) != 0) )
		return (1);
	return (0);
}

/*int		char_counter(char *str)
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
  }*/
int		if_tetro(char *str,int i)
{
	int		col;
	int		row;

	while (str[i] != '\0' || !ft_strlen(str))
	{
		row = 1;
		while (row < 5)
		{
			col = 1;
			while (str[i] != '\n')
			{
				col++;
				i++;
			}
			if (col != 5)
				return (1);
			row++;
			i++;
		}
		if (str[i] != '\0')
			return (1);
	}
	return (0);
}
int		if_tetros(char	*str,int tetro)
{
	int		i;
	int     col;
	int     row;

	i = 0;
	while (tetro-- != 1 && str[i] != '\0')
	{
		row = 1;
		while (row < 5)
		{
			col = 1;
			while (str[i] != '\n' && col >= 0)
			{
				col++;
				i++;
			}
			if (col != 5)
				return (1);
			row++;
			i++;
		}
	}
		if (tetro == 1 && str[i] != '\0')
			if_tetros(str , i);
	return (0);
}
int		check_line(char	*str,int tetro)
{
	int		var;

	if (tetro == 1)
		var = if_tetro(str,0);
	if (tetro >= 1)
		var = if_tetros(str,tetro);
	if (var)
		return (1);
	else
		return (0);
}
int		mother_of_cheker(char *str)
{
	t_valid		*count;
	int			tetrominos;
	count = char_counter(str);
	if (checker(count))
		return (1);
	tetrominos = count->hash / 4;
	// check if tetrominos 1 or maney 
	if (check_line(str,tetrominos))
		return (1);
	return (0);
}
int		check_connection_if_valid(char *str)
{
	int		i;
	int		k;
	int		hash;
	int		connection;

	connection = 0;
	hash  = 0;
	i = 0;
	while (str[i] || !ft_strlen(str))
	{
		k = 0;
		while (k++ < 21)
		{
			if (str[i] == '#')
			{
				hash++;
				connection += check_connection(str,i);
				if (hash < 6 && hash == 4)
					return (1);
			}
			i++;
		}
	}
	return (0);
}
int		all_chekers(char *str)
{
	if (check_char(str))
		return (1);
	if (mother_of_cheker(str))
		return (1);
	if (check_connection_if_valid(str))
		return (1);
	return (0);
}
char	*extract(void  *str,size_t size)
{
	void	*tmp;
	size_t  sizet;

	tmp = (char*)malloc(sizeof(char) * size);
	ft_memset(tmp, 0, size);
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


	size = 22;	
	fd  = open(file,O_RDONLY);
	buff = ft_strnew(21);
	tetrominos= ft_strnew(21);
	while ((ret = read(fd,buff,21)))
	{
		ft_strcat(tetrominos,buff);
		size = size + 21;
		tetrominos = extract(tetrominos,size);
		ft_memset(buff,0,21);
	}
	if (all_chekers(tetrominos))
	{
		ft_putendl("error ");
		exit(0);
	}
	else
		ft_putendl("work");
	return (tetrominos);
}
int main(int argc,char **argv)
{
	char	*str;

	str = ft_readfile(argv[1]);
	ft_putendl(str);
}
