/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:30:56 by arthur            #+#    #+#             */
/*   Updated: 2021/07/25 14:45:28 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/pipex.h"

int	*create_pipe_list(t_instance *pipex, int output)
{
	int	*fds;
	int	fd[2];
	int	i;

	i = 0;
	fds = new (sizeof(int), pipex->count_cmd * 2);
	fds[0] = pipex->file_in;
	i++;
	while (i < (pipex->count_cmd * 2) - 1)
	{
		pipe(fd);
		fds[i] = fd[1];
		fds[i + 1] = fd[0];
		i += 2;
	}
	fds[i] = output;
	return (fds);
}

pid_t	exec_cmd(t_fork_n *n)
{
	n->fds = create_pipe_list(n->pipex,
			open(n->pipex->file_out, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU));
	n->pid = new(sizeof(pid_t), n->pipex->count_cmd);
	while (n->i < (n->pipex->count_cmd * 2) && n->cmd)
	{
		errno = 0;
		if (n->i % 2 == 0)
			exec_fork(n);
		n->i += 2;
	}
	n->i = 0;
	while (n->i < n->pipex->count_cmd)
	{
		if (n->pid[n->i] != -1)
		{
			waitpid(n->pid[n->i], &n->status, 0);
			if (WIFEXITED(n->status))
				n->ret = WEXITSTATUS(n->status);
			if (n->ret == 127)
				ft_printf("pipex: command not found: %s\n", n->cmd[n->i].cmd);
		}
		n->i++;
	}
	return (n->ret);
}

pid_t	exec(t_instance *pipex)
{
	t_fork_n	n;

	n.cmd = new (sizeof(t_exec_cmd), pipex->count_cmd);
	n.pipex = pipex;
	n.i = 0;
	while (n.pipex->cmd != NULL)
	{
		n.cmd[n.i] = parse_cmd(n.pipex->cmd->cmd, n.pipex);
		n.pipex->cmd = n.pipex->cmd->next;
		n.i++;
	}
	n.ret = 0;
	n.count_fork = 0;
	n.i = 0;
	return (exec_cmd(&n));
}
