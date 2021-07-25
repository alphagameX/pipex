/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 00:10:42 by atinseau          #+#    #+#             */
/*   Updated: 2021/07/09 15:25:36 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		e;

	if (!s1 || !s2)
		return (NULL);
	str = new(sizeof(char), (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2)) + 1);
	if (!str)
		return (NULL);
	e = 0;
	while (*s1 != '\0')
		str[e++] = *s1++;
	while (*s2 != '\0')
		str[e++] = *s2++;
	str[e] = '\0';
	return (str);
}
