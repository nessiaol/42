/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnastro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:08:46 by gnastro           #+#    #+#             */
/*   Updated: 2021/05/19 17:21:16 by gnastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	n;
	size_t	i;
	size_t	z;

	n = 0;
	i = 0;
	new = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!s || !new)
		return (NULL);
	while ((int)n < ft_wordcount(s, c))
	{
		z = 0;
		new[n] = ft_strnew(ft_wordlen(&s[i], c) + 1);
		if (!new[n])
			new[n] = NULL;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			new[n][z++] = s[i++];
		new[n][z] = '\0';
		n++;
	}
	new[n] = 0;
	return (new);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	n;

	n = 0;
	new = (char *)malloc(sizeof(char) * (len + 1 ));
	if (s == NULL || start > ft_strlen(s) || new == NULL)
		return (NULL);
	while (n++ < len && s[start] != '\0')
		new[n - 1] = s[start + n - 1];
	new[n - 1] = '\0';
	return (new);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr = nbr * sign;
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (nbr);
}

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	}
	return (0);
}

char	*ft_strchr(const char *s1, int s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == (char)s2)
		{
			return ((char *)&s1[i]);
		}
		i++;
	}
	if (s1[i] == (char)s2)
	{
		return ((char *)&s1[i]);
	}
	return (NULL);
}
