/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:11:18 by dmangola          #+#    #+#             */
/*   Updated: 2021/10/19 15:46:38 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"

int	ft_pwd(void)
{
	// long	path_dim;
	char	*buf;

	buf = NULL;
	printf("%s\n", getcwd(buf, 300));

	free(buf);
	// path_dim = pathconf(".", _PC_PATH_MAX);		//sta pathconf non la trovo tra le consentite
	// assert(path_dim != 1);
	// buf = malloc(path_dim * sizeof(*buf));
	// assert(buf);
	// if (getcwd(buf, path_dim) == NULL)
	// {
	// 	perror("error in getting current directory");
	// 	exit(EXIT_FAILURE);
	// }
	// else
	// 	printf("%s\n", buf);
	// free(buf);
	return (EXIT_SUCCESS);
}