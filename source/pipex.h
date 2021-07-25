/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:24:19 by arthur            #+#    #+#             */
/*   Updated: 2021/07/25 14:50:31 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdio.h>
# ifndef BONUS
#  define BONUS 0
# endif

struct s_exec_cmd
{
	char	*cmd;
	char	**args;
	int		valid;
};

typedef struct s_exec_cmd	t_exec_cmd;

struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
};
typedef struct s_cmd		t_cmd;

struct	s_instance
{
	int		file_in;
	char	*file_out;
	t_cmd	*cmd;
	int		count_cmd;
	char	**path;
	char	**envp;
};
typedef struct s_instance	t_instance;

struct s_fork_n
{
	pid_t		*pid;
	pid_t		ret;
	int			*fds;
	int			status;
	int			i;
	int			count_fork;
	t_instance	*pipex;
	t_exec_cmd	*cmd;
};
typedef struct s_fork_n		t_fork_n;

void		parse(t_instance *pipex, int argc, char *argv[]);
char		*getpath(char *envp[]);
pid_t		exec(t_instance *pipex);
char		*try_to_get_path(char **path, char *cmd);
t_exec_cmd	parse_cmd(const char *str, t_instance *pipex);
char		**get_cmd_args(char *name, int i, char **args);
t_cmd		*create_cmd(char *cmd);
void		add_cmd(t_cmd **old, t_cmd *new);
void		print_cmd(t_cmd *cmd);
void		exec_fork(t_fork_n *n);

/*
** NORM
**
*/

void		valid_split(t_exec_cmd *cmd, t_instance *pipex, int i, char **args);

#endif