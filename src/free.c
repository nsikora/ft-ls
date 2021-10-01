/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:02:45 by nsikora           #+#    #+#             */
/*   Updated: 2021/10/01 13:02:47 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ls.h"

void free_data(char **paths, t_flags *flags)
{
    int i;

    i = 0;
    free(flags);
    while (paths[i]) {
        free(paths[i]);
        i++;
    }
    free(paths);
    exit(0);
}