/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:46:45 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/31 11:00:14 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd1_operation(char *argv[], char *envp[], int pipe_fd[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		close_fds(pipe_fd, 2);
		ft_errmsg("Open Failed\n", infile);
	}
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile);
	execute(argv[2], envp);
}

void	ft_cmd2_operation(char *argv[], char *envp[], int pipe_fd[])
{
	int	outfile;
	//int	infilechk;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		close_fds(pipe_fd, 2);
		ft_errmsg("File Creation Failed\n", outfile);
	}
	// infilechk = open(argv[1], O_RDONLY);
	// if (infilechk < 0)
	// {
	// 	close_fds(pipe_fd, 2);
	// 	ft_errmsg("", infilechk);
	// }
	// close(infilechk);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(outfile);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	pipe_fd[2];
	int	pid[2];
	int	status;

	if (argc != 5)
		ft_errmsg("wrong format, correct: <infile arg1 | arg2 > outfile\n", 127);
	if (pipe(pipe_fd) == -1)
		ft_errmsg("Pipe Failed\n", 32);
	pid[0] = fork();
	if (pid[0] == -1)
		ft_errmsg("Fork Failed\n", -1);
	if (pid[0] == 0)
		ft_cmd1_operation(argv, envp, pipe_fd);
	pid[1] = fork();
	if (pid[1] == -1)
		ft_errmsg("Fork Failed\n", -1);
	if (pid[1] == 0)
		ft_cmd2_operation(argv, envp, pipe_fd);
	close_fds(pipe_fd, 2);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (128 + WTERMSIG(status));
}
