 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:22 by dmangola          #+#    #+#             */
/*   Updated: 2021/09/08 15:44:24 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"

static void	ft_normal_case(int arg_check, char *pwd)
{
	char	*tmp;
	struct stat sb;

	if (arg_check == 0)
	{
		tmp = ft_strjoin(pwd, "/");
		if (stat(ft_strjoin(tmp, g_shell->splitted_line[1]), &sb) == 0 && \
			S_ISDIR(sb.st_mode))
		{
			chdir(ft_strjoin(tmp, g_shell->splitted_line[1]));
			ft_putstr_fd("passo da qua", 1);
		}
		else
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putstr_fd(tmp, 2);
			ft_putstr_fd("\n", 2);
		}
	}
}

static void	ft_cases(char **envp, int arg_check, char *home, char *oldpwd)
{
	//char	*tilde;
	//char	*tmp;

	if (arg_check == 1)
	{
		home = envp[ft_index_position(envp, "HOME=")] + 5;
		chdir(home);
		printf("\n%s\n", home);
	}
	if (arg_check == 2)
	{
		ft_putstr_fd(envp[ft_index_position(envp, "OLDPWD=")] + 7, 1);
		oldpwd = envp[ft_index_position(envp, "OLDPWD=")] + 7;
		chdir(oldpwd);
		printf("\n%s\n", oldpwd);
	}
	if (arg_check == 3)
	{
		ft_create_tilde_path(home);
		//tilde = ft_strjoin(home, g_shell->cd.tilde_path);

	}
}

int	ft_if_cd(char **envp, int arg_check)
{
	char	*home = NULL;
	char	*pwd;
	char	*oldpwd = NULL;

	pwd = envp[ft_index_position(envp, "PWD=")] + 4;
	ft_cases(envp, arg_check, home, oldpwd);
	ft_normal_case(arg_check, pwd);
	return (0);
}

int	ft_cd(char **envp)
{
	if (!g_shell->splitted_line[1])
		return (ft_if_cd(envp, 1));
	else if (!(ft_strcmp(g_shell->splitted_line[1], "-")))
		return (ft_if_cd(envp, 2));
	else if (!(ft_strcmp(g_shell->splitted_line[1], "~")))
		return (ft_if_cd(envp, 3));
	else
		return (ft_if_cd(envp, 0));
}