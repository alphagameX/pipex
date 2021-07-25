/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 13:18:23 by arthur            #+#    #+#             */
/*   Updated: 2021/07/25 14:46:42 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/pipex.h"

void	exec_fork(t_fork_n *n)
{
	n->pid[n->count_fork] = fork();
	if (n->pid[n->count_fork] == 0)
	{
		dup2(n->fds[n->i], STDIN_FILENO);
		close(n->fds[n->i]);
		dup2(n->fds[n->i + 1], STDOUT_FILENO);
		close(n->fds[n->i + 1]);
		errno = execve(n->cmd[n->count_fork].cmd,
				n->cmd[n->count_fork].args, n->pipex->envp);
		if (errno == -1)
			errno = 127;
		destroy_stack();
		exit(errno);
	}
	n->count_fork++;
	close(n->fds[n->i]);
	close(n->fds[n->i + 1]);
}
