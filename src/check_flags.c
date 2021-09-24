/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:17:37 by nsikora           #+#    #+#             */
/*   Updated: 2021/09/24 18:17:39 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ls.h"

int        check_flags(char c, t_flags *flags) {
    int ret;
    
    ret = 1;
    if (c == 'R')
    {
        flags->R = TRUE;
        return (0);
    }
    if (c == 'a')
    {
        flags->a = TRUE;
        return (0);
    }
    if (c == 'f')
    {
        flags->f = TRUE;
        return (0);
    }
    if (ret == 1)
        ret = check_flags_next(c, flags);
    return (ret);
}
int        check_flags_next(char c, t_flags *flags) {
    if (c == 'l')
    {
        flags->l = TRUE;
        return (0);
    }
    if (c == 'r')
    {
        flags->r = TRUE;
        return (0);
    }
    if (c == 't')
    {
        flags->t = TRUE;
        return (0);
    }
    return (1);
}