/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:01:38 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/02 22:50:26 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_extra_chk(char *fcommand)
{
	if (access(fcommand, F_OK) == 0)
	{
		return (access(fcommand, X_OK | R_OK));
	}
	else
		return (-1);
}

char	**ft_get_paths(char *env[])
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i];
			break ;
		}
		i++;
	}
	if (!env[i])
	{
		ft_errmsg("No Path Variable.\n", -1);
		exit(1);
	}
	paths = ft_split((path + 5), ':');
	if (!paths)
		ft_errmsg("Could not find path.\n", -1);
	return (paths);
}

char	*ft_find_executable(char *envp[], char *cmd)
{
	int		i;
	char	*full_path;
	char	*temp;
	char	**paths;

	i = 0;
	paths = ft_get_paths(envp);
	while (paths[i])
	{
		temp = ft_strjoin_gnl(paths[i], "/");
		full_path = ft_strjoin_gnl(temp, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	free(paths);
	return (NULL);
}

void	ft_path_as_args_chk(char *cmd, char **envp)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, args, envp);
			ft_farray(args);
			ft_errmsg("Command not found\n", 127);
		}
		else
		{
			ft_farray(args);
			return ;
		}
	}
	return ;
}

int	execute(char *cmd, char *envp[])
{
	char	*exve;
	char	**fcommand;

	if (ft_strchr(cmd, '/') != 0)
		ft_path_as_args_chk(cmd, envp);
	fcommand = ft_split(cmd, ' ');
	if (!fcommand || !fcommand[0])
	{
		ft_farray(fcommand);
		ft_errmsg("Invalid or Empty Command!!\n", 126);
	}
	if (!ft_extra_chk(fcommand[0]))
		exve = ft_strdup(fcommand[0]);
	else
		exve = ft_find_executable(envp, fcommand[0]);
	if (!exve)
	{
		ft_farray(fcommand);
		ft_errmsg("Command not found\n", 127);
	}
	execve(exve, fcommand, envp);
	ft_errmsg("Execve Failed, Unable to Execute\n", 126);
	free(exve);
	ft_farray(fcommand);
	exit(1);
}
