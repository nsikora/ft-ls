/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_by.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:38:30 by nsikora           #+#    #+#             */
/*   Updated: 2021/09/24 12:38:33 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ls.h"

char    **order_by_alphabetical(DIR *d) {
    struct dirent	*dir;
    char            **flags;
    int             i;

    i = 0;
    dir = readdir(d);
    while (dir)
	{
        dir = readdir(d);
        i++;
    }
    if ((flags = malloc(sizeof(char *) * i)) == 0)
		return (NULL);
    return (flags);
}