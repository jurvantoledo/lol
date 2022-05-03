/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 13:23:08 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/04/13 16:40:37 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	here_fork(char *str, char *limiter)
{
	pid_t	reader;
	int		fd[2];

	if (pipe(fd) == -1)
		pexit("Pipe failed", 1);
	reader = fork();
	if (reader == -1)
		pexit("Fork failed", 1);
	if (reader == 0)
	{
		close(fd[0]);
		while (str)
		{
			if (ft_strncmp(str, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], str, ft_strlen(str));
			str = get_next_line(STDOUT_FILENO);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

static void	here_doc(char *limiter)
{
	char	*str;

	str = get_next_line(STDOUT_FILENO);
	here_fork(str, limiter);
}

static void	run_child_process(int argc, char *argv[], char *envp[], int i)
{
	while (i < argc - 2)
	{
		child_process(argv[i], envp);
		i++;
	}
}

static void	pipex(int argc, char *argv[], char *envp[], int i)
{
	t_pipex	data;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		data.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (data.outfile < 0)
			pexit("Open failed", 1);
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		data.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (data.outfile < 0)
			pexit("Open failed", 1);
		data.infile = open(argv[1], O_RDONLY);
		if (data.infile < 0)
			pexit("Open failed", 1);
		dup2(data.infile, STDIN_FILENO);
	}
	run_child_process(argc, argv, envp, i);
	dup2(data.outfile, STDOUT_FILENO);
	run_process(argv[argc - 2], envp);
	close(data.outfile);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	i = 5;
	if (argc < i)
		pexit("Not enough arguments", 1);
	pipex(argc, argv, envp, i);
	return (0);
}
