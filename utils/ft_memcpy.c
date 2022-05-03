/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 12:16:20 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/11 12:16:27 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	i = 0;
	cdst = (char *)dst;
	csrc = (char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
