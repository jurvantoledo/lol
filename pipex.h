/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 14:59:10 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/04/08 12:25:47 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"

# define PIPEX_H

typedef struct s_pipex {
	int		infile;
	int		outfile;
}	t_pipex;

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	pexit(char *str, int exit_code);
void	free_path(char **path);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*parse_path(char *argv, char *envp[]);
void	run_process(char *argv, char *envp[]);
void	child_process(char *argv, char *envp[]);

#endif