/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:54:42 by atinseau          #+#    #+#             */
/*   Updated: 2021/07/25 14:52:59 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		e;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	str = new (sizeof(char), (ft_gnl_strlen(s1) + ft_gnl_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	e = 0;
	i = 0;
	while (s1 && s1[i] != '\0')
		str[e++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[e++] = s2[i++];
	str[e] = '\0';
	ft_free(s1);
	return (str);
}

int	ft_gnl_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
