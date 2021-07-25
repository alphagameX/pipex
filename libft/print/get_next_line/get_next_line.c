/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:34:38 by atinseau          #+#    #+#             */
/*   Updated: 2021/07/25 14:53:34 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_return(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_substr(char **str, int start, int len, int is_ft_free)
{
	char	*s;
	int		i;

	i = 0;
	s = new (sizeof(char), len + 1);
	if (!s)
		return (NULL);
	if (*str == NULL)
	{
		*s = '\0';
		return (s);
	}
	while (*(*str + start) && i < len)
	{
		s[i] = *(*str + start);
		i++;
		start++;
	}
	s[i] = '\0';
	if (is_ft_free == 1)
		ft_free(*str);
	return (s);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str;
	char		*temp;

	temp = new (sizeof(char), BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !temp)
		return (-1);
	ret = 1;
	while (has_return(str) == 0 && ret)
	{
		ret = read(fd, temp, BUFFER_SIZE);
		if (ret == -1)
		{
			ft_free(temp);
			return (-1);
		}
		temp[ret] = '\0';
		str = ft_gnl_strjoin(str, temp);
	}
	ft_free(temp);
	if (!has_return(str))
		return (last_line(line, &str));
	*line = gnl_substr(&str, 0, pos_n(str), 0);
	str = gnl_substr(&str, pos_n(str) + 1, ft_gnl_strlen(str) - pos_n(str), 1);
	return (1);
}

int	last_line(char **line, char **str)
{
	*line = gnl_substr(str, 0, ft_gnl_strlen(*str), 0);
	if (*str)
	{
		ft_free(*str);
		*str = NULL;
	}
	return (0);
}

int	pos_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}
