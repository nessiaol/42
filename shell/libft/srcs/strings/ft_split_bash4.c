/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bash4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:25:17 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/26 15:04:41 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_case_3_check(char *changes, int *i, int len)
{
	if (i[0] + 3 <= len && changes[i[0]] == 1 && ((changes[i[0] + 1] == 3 && \
	changes[i[0] + 2] == 2) || (changes[i[0] + 1] == 5 && \
	changes[i[0] + 2] == 4)) && changes[i[0] + 3] < 2)
		return (1);
	return (0);
}

int	ft_case_2_check(char *changes, int *i, int len)
{
	if (i[0] > 0 && i[0] + 2 < len && !changes[i[0] - 1] && ((changes[i[0]] == 2 && \
	(changes[i[0] + 1] == 3 || changes[i[0] + 1] == 5)) || (changes[i[0]] == 4 && \
	(changes[i[0] + 1] == 3 || changes[i[0] + 1] == 5))) && !changes[i[0] + 2])
		return (1);
	return (0);
}

int	ft_case_1_check(char *changes, int *i, int len)
{
	if (i[0] > 0 && i[0] + 1 < len && !changes[i[0] - 1] && \
		changes[i[0]] > 1 && !changes[i[0] + 1])
		return (1);
	return (0);
}

void	ft_case_2(char ***splitted, char *line, int *i)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (*splitted)[i[1]];
	tmp2 = ft_strdup(line + i[0] + 2);
	(*splitted)[i[1]] = ft_strjoin(tmp1, tmp2);
	i[0] += 2;
	ft_if_free((void **)&tmp1);
	ft_if_free((void **)&tmp2);
}

void	ft_case_1(char ***splitted, char *line, int *i)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (*splitted)[i[1]];
	tmp2 = ft_strdup(line + i[0] + 1);
	(*splitted)[i[1]] = ft_strjoin(tmp1, tmp2);
	i[0] += 1;
	ft_if_free((void **)&tmp1);
	ft_if_free((void **)&tmp2);
}
