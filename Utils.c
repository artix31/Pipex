/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:01:38 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/28 16:36:52 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_extra_chk(char *fcommand)
{
	if (access(fcommand, F_OK ) == 0)
	{
		return (access(fcommand, X_OK | R_OK));
	}
	else
		return (0);
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
		exit(-1);
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
		//free(temp);
		if (access(full_path, X_OK) == 0)
		{
			ft_farray(paths);
			//free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free(paths);
	return (NULL);
}

int	execute(char *cmd, char *envp[])
{
	char	*exve;
	char	**fcommand;

	fcommand = ft_split(cmd, ' ');
	if (!fcommand || !fcommand[0])
	{
		ft_farray(fcommand);
		free(fcommand);
		ft_errmsg("Invalid or Empty Command!!", -1);
	}
	if (ft_extra_chk(fcommand[0]))
		exve = ft_strdup(fcommand[0]);
	else
		exve = ft_find_executable(envp, fcommand[0]);
	if (!exve)
	{
		ft_farray(fcommand);
		ft_errmsg("Command not found || Invalid Command", 127);
	}
	execve(exve, fcommand, envp);
	ft_errmsg("Execve Failed, Unable to Execute\n", -1);
	ft_farray(fcommand);
	exit(1);
}
