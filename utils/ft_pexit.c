/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pexit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:54:54 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/04/06 15:55:07 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pexit(char *str, int exit_code)
{
	perror(str);
	exit(exit_code);
}
