/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:07:44 by dmangola          #+#    #+#             */
/*   Updated: 2021/10/07 13:36:31 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

// int	ft_mtx_len_hei(char **m, short info)
// {
// 	int	i;
// 	int	j;
// 	int	height;

// 	i = 0;
// 	height = -1;
// 	while (m[i])
// 	{
// 		j = 0;
// 		while (m[i][j])
// 		{
// 			if (j > height)
// 				height = j;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (info == 0)
// 		return (i);
// 	return (j);
// }

// static char	**ft_skip_in_mtx(char **m, char *to_skip)
// {
// 	char	**words_to_skip;
// 	char	**dst;
// 	short	num_words;
// 	short	i;
// 	short	j;

// 	j = 0;
// 	words_to_skip = ft_bnessi_split(to_skip, ' ');
// 	while (words_to_skip)
// 		j++;
// 	num_words = j;
// 	dst = malloc(sizeof(**m));
// 	i = -1;
// 	while (m[++i])
// 	{
// 		j = 0;
// 		while (j < num_words)
// 		{
// 			if (ft_strcmp(words_to_skip[j], m[i]))
// 			{
// 				ft_putstr_fd("SALTATO QUALCOSA\n", 1);
// 				break ;
// 			}
// 			dst[i] = ft_strdup(m[i]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return(dst);
// }

char	**ft_mtxcpy(char **m)
{
	char	**dst;
	int		i;

	dst = malloc(sizeof(**m));
	if (!dst)
	{
		ft_putstr_fd("Malloc error in copying envp\n", 1);
		return ((char **)1);
	}
	i = 0;
	dst = m;
	return (dst);
}

void	ft_mtxprint(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		ft_putstr_fd(m[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}