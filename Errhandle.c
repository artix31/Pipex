/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:01:54 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/31 14:04:00 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errmsg(char *msg, int errno)
{
	if ((errno == 42) | (errno == 127))
	{
		ft_putstr_fd(msg, 2);
		exit(errno);
	}
	else
	{
		perror("");
		exit(errno);
	}
}

void	close_fds(int *fds, int fd_count)
{
	int	i;

	i = 0;
	while (i < fd_count)
	{
		if (fds[i] != -1)
			close(fds[i]);
		i++;
	}
}
