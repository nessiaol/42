/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:17:49 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/05 12:17:50 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "utils.h"
#include "../libft/libft.h"
#include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

int main(int ac, char **av);

#endif