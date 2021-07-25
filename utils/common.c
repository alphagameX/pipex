/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:30:44 by arthur            #+#    #+#             */
/*   Updated: 2021/07/25 14:26:20 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/pipex.h"

char	*getpath(char *envp[])
{
	char	**env;

	env = NULL;
	while (*envp)
	{
		env = ft_split(*envp, '=');
		if (!ft_strncmp(env[0], "PATH", 4))
			return (env[1]);
		envp++;
	}
	return (NULL);
}

char	*try_to_get_path(char **path, char *cmd)
{
	char	*c;

	c = NULL;
	while (*path)
	{
		ft_argv_strjoin(&c, 3, *path, "/", cmd);
		if (access(c, R_OK) != -1)
			return (c);
		path++;
		ft_free(c);
		c = NULL;
	}
	return (NULL);
}
