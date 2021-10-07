/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:14:26 by dmangola          #+#    #+#             */
/*   Updated: 2021/10/07 13:29:31 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"

int	ft_env(char **envp)
{
	//char	**tmp;
	g_shell->env.env_cpy = ft_mtxcpy(envp);
	//g_sh->env.env_cpy = ft_skip_in_mtx(tmp, "PWD OLDPWD");
	ft_mtxprint(g_shell->env.env_cpy);
	if (g_shell->env.env_cpy == (char **)1)
		return (1);
	return (0);
}