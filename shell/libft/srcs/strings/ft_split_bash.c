/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:26:13 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/26 14:27:45 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_save_splitted(char ***splitted, char *line,
	char *changes, int len)
{
	int	i[2];

	i[0] = 0;
	i[1] = -1;
	while (i[0] < len)
	{
		if (ft_case_1_check(changes, i, len))
			ft_case_1(splitted, line, i);
		else if (ft_case_2_check(changes, i, len))
			ft_case_2(splitted, line, i);
		else if (line[i[0]])
			(*splitted)[++i[1]] = ft_strdup(line + i[0]);
		if (line[i[0]])
			while (i[0] < len && line[i[0]])
				++i[0];
		else
		{
			while (i[0] < len && !line[i[0]])
			{
				if (ft_case_3_check(changes, i, len))
					(*splitted)[++i[1]] = ft_strdup("");
				++i[0];
			}
		}
	}
}

int	ft_isescapable(char c)
{
	if (!c)
		return (0);
	if (c == '\'' || c == '"' ||c == '>' || \
		c == '<' ||c == '|' ||c == ';' || c == '$' || c == '\\')
		return (1);
	return (0);
}

static void	ft_count_escapes(char *line, char **escapes, int i, int in_quote)
{
	*escapes = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	while (line[i])
	{
		if (line[i] == '\'')
			ft_jump_quotes_text(line, &i, 0);
		else if (line[i] == '"' && !ft_isescaped(line, i - 1) && \
		in_quote && ++i)
			in_quote = 0;
		else if (line[i] == '"' && !ft_isescaped(line, i - 1) && \
		!in_quote && ++i)
			in_quote = 1;
		else if (line[i] == '$')
		{
			while (line[i] && line[i] != ' ')
				++i;
		}
		else if (line[i] == '\\' && !ft_isescaped(line, i - 1))
		{
			if (!in_quote || (in_quote && ft_isescapable(line[i + 1])))
				(*escapes)[i] = 1;
			i += 2;
		}
		else
			++i;
	}
}

static char	*ft_remove_escapes(char *line, char **escapes)
{
	char	*new;
	int		i;

	if (!line || !ft_strlen(line))
		return (0);
	ft_count_escapes(line, escapes, 0, 0);
	new = 0;
	i = 0;
	while (line[i])
	{
		if (!(*escapes)[i])
			new = ft_strcharjoin(new, line[i]);
		++i;
	}
	return (new);
}

char	**ft_split_bash(char *line)
{
	char	**splitted;
	char	*escapes;
	char	*changes;
	int		len;

	line = ft_remove_escapes(line, &escapes);
	len = ft_strlen(line) + 1;
	changes = (char *)ft_calloc(len, sizeof(char));
	line = ft_separate_strs_bash(line, escapes, &changes, 0);
	splitted = (char **)ft_calloc(ft_count_strs_bash(line, changes, len, 0), \
		sizeof(char *));
	ft_save_splitted(&splitted, line, changes, len);
	ft_if_free((void **)&line);
	ft_if_free((void **)&escapes);
	ft_if_free((void **)&changes);
	return (splitted);
}
