/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:02:46 by sberrich          #+#    #+#             */
/*   Updated: 2019/04/10 19:32:56 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int l;

	if (!s)
	{
		return (NULL);
	}
	l = ft_strlen(s) - 1;
	i = 0;
	while (ft_strlen(s) && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
		l--;
	return (ft_strsub(s, i, (l - i + 1) >= 0 ? (l - i + 1) : 0));
}
