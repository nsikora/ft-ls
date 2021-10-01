/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:05:08 by nsikora           #+#    #+#             */
/*   Updated: 2021/09/17 19:07:24 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h> 
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define TRUE   0
# define FALSE  1

typedef struct		s_flags
{
    int             R;
    int             a;
    int             f;
    int             l;
    int             r;
    int             t;
    int             empty;
    int             illegal;
}					t_flags;

void	read_info(char **paths, t_flags *flags);
void	display_ls_noflag(DIR *d, t_flags *flags);
void	error_message(char *path);
void    initialize_flags(t_flags *flags);
void    get_flags(char **av, t_flags *flags);
char    **get_paths(char **av);
void    order_by_alphabetical(char **str);
void    swap(char **str1, char **str2);
int     check_flags(char c, t_flags *flags);
int     check_flags_next(char c, t_flags *flags);
void    show_illegal_option(char c, t_flags *flags);
void    free_data(char **paths, t_flags *flags);
int     get_str_nb(char **str);
void    fill_paths_data(int i, int len, char **av, char **paths);
void    display_mode(struct dirent	*dir, t_flags *flags, int i);

#endif
