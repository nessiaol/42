/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bash3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:09:08 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/26 14:36:15 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_case_3_check(char *changes, int i, int len)
{
	if (i + 3 <= len && changes[i] == 1 && ((changes[i + 1] == 3 && \
				changes[i + 2] == 2) || (changes[i + 1] == 5 && \
				changes[i + 2] == 4)) && changes[i + 3] < 2)
		return (1);
	return (0);
}

int	ft_count_case_2_check(char *changes, int i, int len)
{
	if (i > 0 && i + 2 < len && !changes[i - 1] && ((changes[i] == 2 && \
		(changes[i + 1] == 3 || changes[i + 1] == 5)) || \
		(changes[i] == 4 && (changes[i + 1] == 3 || \
		changes[i + 1] == 5))) && !changes[i + 2])
		return (1);
	return (0);
}

int	ft_count_case_1_check(char *changes, int i, int len)
{
	if (i > 0 && i + 1 < len && !changes[i - 1] && \
		changes[i] > 1 && !changes[i + 1])
		return (1);
	return (0);
}

int	ft_count_strs_bash(char *line, char *changes, int len, int i)
{
	int	n;

	n = 1;
	while (i < len)
	{
		if (ft_count_case_1_check(changes, i, len))
			i += 1;
		else if (ft_count_case_2_check(changes, i, len))
			i += 2;
		else if (line[i])
			++n;
		if (line[i])
			while (i < len && line[i])
				++i;
		else
		{
			while (i < len && !line[i])
			{
				if (ft_count_case_3_check(changes, i, len))
					++n;
				++i;
			}
		}
	}
	return (n);
}
