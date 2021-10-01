/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:39:42 by nsikora           #+#    #+#             */
/*   Updated: 2021/09/24 13:39:44 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ls.h"

void        initialize_flags(t_flags *flags)
{
    flags->R = FALSE;
    flags->a = FALSE;
    flags->f = FALSE;
    flags->l = FALSE;
    flags->r = FALSE;
    flags->t = FALSE;
    flags->empty = TRUE;
    flags->illegal = FALSE;
}

void        show_illegal_option(char c, t_flags *flags) {
    flags->illegal = TRUE;
    ft_putstr("ft_ls: illegal option -- ");
    ft_putchar(c);
    ft_putstr("\n usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
    ft_putendl(" [file ...]");
}

void        get_flags(char **av, t_flags *flags) {
    int     i;
    int     j;
    int     ret;

    i = 1;
    j = 1;
    ret = 0;
    while (av[i] && av[i][0] == '-' && av[i][1])
    {
        while (av[i][j]) {
            ret = check_flags(av[i][j], flags);
            if (ret == 1) {
                show_illegal_option(av[i][j], flags);
                return ;
            }
            j++;
        }
        j = 1;
        i++;
    }
}

void        fill_paths_data(int i, int len, char **av, char **paths)
{
    i = 1;
    len = 0;
    while (av[i]) {
        if (av[i][0] != '-' || (av[i][0] == '-' && !av[i][1]))
        {
            paths[len] = malloc(sizeof(char) * ft_strlen(av[i]) + 1);
            ft_memcpy(paths[len], av[i], ft_strlen(av[i]));
            paths[len][ft_strlen(av[i])] = '\0';    
            len++;
        }
        i++;
    }
    paths[len] = NULL;
}

char        **get_paths(char **av) {
    char    **paths;
    int     i;
    int     len;

    i = 1;
    len = 0;
    while (av[i]) {
        if (av[i][0] != '-' || (av[i][0] == '-' && !av[i][1]))
            len++;
        i++;
    }
    if (len == 0)
    {
        paths = malloc(sizeof(char *) * 1 + 1);
        paths[0] = malloc(sizeof(char) * 1);
        paths[0][0] = '.';
        paths[1] = NULL;
        return paths;
    }
    paths = malloc(sizeof(char *) * len + 1);
    fill_paths_data(i, len, av, paths);
    return (paths);
}