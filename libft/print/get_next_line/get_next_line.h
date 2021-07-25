/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:11:46 by atinseau          #+#    #+#             */
/*   Updated: 2021/07/09 15:38:06 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../../mem/alloc/mem.h"

# define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		ft_gnl_strlen(char *str);
int		pos_n(char *str);
int		last_line(char **line, char **str);

#endif
