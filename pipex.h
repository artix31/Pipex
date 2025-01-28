/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:27:23 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/24 04:51:53 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include <sys/wait.h>
# include <stdio.h>

//Errhandle
void	ft_errmsg(char *msg, int errno);
void	close_fds(int *fds, int fd_count);
//Pipex
void	ft_cmd1_operation(char *argv[], char *envp[], int pipe_fd[]);
void	ft_cmd2_operation(char *argv[], char *envp[], int pipe_fd[]);
//Utils
char	**ft_get_paths(char *env[]);
char	*ft_find_executable(char *envp[], char *cmd);
int		execute(char *cmd, char *envp[]);

#endif
