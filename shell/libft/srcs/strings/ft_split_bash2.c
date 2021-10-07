/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bash2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:07:30 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/25 12:22:42 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_in_quote(char *line, int i, int *in_quote)
{
	if (line[i] == '\'' && *in_quote == 1)
		*in_quote = 0;
	else if (line[i] == '"' && !ft_isescaped(line, i - 1) && *in_quote == 2)
		*in_quote = 0;
	else if (line[i] == '\'' && !ft_isescaped(line, i - 1) && !(*in_quote))
		*in_quote = 1;
	else if (line[i] == '"' && !ft_isescaped(line, i - 1) && !(*in_quote))
		*in_quote = 2;
}

static int	ft_save_dollar(char **new, char *line, int *i, int *in_quote)
{
	if (line[*i] == '$' && *in_quote != 1)
	{	
		(*new)[*i] = line[*i];
		++(*i);
		while (line[*i])
		{
			ft_check_in_quote(line, *i, in_quote);
			if (line[*i] == ' ' && !(*in_quote))
				break ;
			(*new)[*i] = line[*i];
			++(*i);
		}
		*in_quote = 0;
		return (1);
	}
	return (0);
}

static void	ft_save_change(char *line, char **new, char **changes, int i)
{
	static int	open = 0;

	(*new)[i] = 0;
	if (line[i] == ' ')
		(*changes)[i] = 1;
	else if (line[i] == '\'')
	{
		if (open)
			(*changes)[i] = 2;
		else
			(*changes)[i] = 3;
	}
	else if (line[i] == '"')
	{
		if (open)
			(*changes)[i] = 4;
		else
			(*changes)[i] = 5;
	}
	if (open && line[i] != ' ')
		open = 0;
	else if (!open && line[i] != ' ')
		open = 1;
}

int	ft_escapes_count(char *escapes, int to)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < to)
	{
		if (escapes[i])
			++n;
		++i;
	}
	return (n);
}

char	*ft_separate_strs_bash(char *line, char *escapes, char **changes,
	int in_quote)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)ft_calloc(ft_strlen(line) + 1, sizeof(char));
	while (line[i])
	{
		ft_check_in_quote(line, i, &in_quote);
		if (ft_save_dollar(&new, line, &i, &in_quote))
			continue ;
		if (((line[i] == ' ' && !in_quote && !escapes[i - ft_escapes_count(escapes, i)]) || \
			((line[i] == '\'' && in_quote != 2) || \
			(line[i] == '"' && in_quote != 1))))
			ft_save_change(line, &new, changes, i);
		else
			new[i] = line[i];
		++i;
	}
	ft_if_free((void **)&line);
	return (new);
}
