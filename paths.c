/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 11:59:06 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/04/08 12:25:19 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		i++;
		free(path[i]);
	}
	free(path);
}

char	*parse_path(char *argv, char *envp[])
{
	char	**mypath;
	int		i;
	char	*temp;
	char	*new_path;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5))
		i++;
	mypath = ft_split(&envp[i][5], ':');
	if (!mypath)
		return (0);
	i = 0;
	while (mypath[i])
	{
		temp = ft_strjoin(mypath[i], "/");
		new_path = ft_strjoin(temp, argv);
		free(temp);
		if (access(new_path, F_OK) == 0)
			return (new_path);
		free(new_path);
		i++;
	}
	free_path(mypath);
	pexit("command not found", 127);
	return (0);
}
