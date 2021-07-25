/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:28:07 by arthur            #+#    #+#             */
/*   Updated: 2021/07/25 14:47:20 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_instance	pipex;
	pid_t		ret;

	parse(&pipex, argc, argv);
	pipex.path = ft_split(getpath(envp), ':');
	pipex.envp = envp;
	ret = exec(&pipex);
	destroy_stack();
	return (ret);
}
