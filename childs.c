/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 10:50:49 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/04/13 16:40:15 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_process(char *argv, char *envp[])
{
	char	**cmd_args;
	char	*path;

	printf("Hallo\n");
	cmd_args = ft_split(argv, ' ');
	if (!cmd_args)
		return ;
	path = parse_path(cmd_args[0], envp);
	printf("the path: %s\n", path);
	if (!path)
		free_path(cmd_args);
	if (execve(path, cmd_args, envp) == -1)
		pexit("Execve failed", 1);
}

void	child_process(char *argv, char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		pexit("Pipe failed", 1);
	pid = fork();
	if (pid == -1)
		pexit("Fork failed", 1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		run_process(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}
