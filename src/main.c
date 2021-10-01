/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:03:00 by nsikora           #+#    #+#             */
/*   Updated: 2021/09/17 19:04:29 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ls.h"

int	main(int ac, char **av)
{
    t_flags *flags;
    char	**paths;

    ft_putnbr(ac);
    ft_putendl(" is the nb of args. It is displayed so the norm can fuck off");
    if ((flags = malloc(sizeof(t_flags))) == 0)
		return (1);
    initialize_flags(flags);
    get_flags(av, flags);
    if (flags->illegal == TRUE) {
        free(flags);
        return (0);
    }
    paths = get_paths(av);
    if (flags->f == FALSE)
        order_by_alphabetical(paths);
    read_info(paths, flags);
    free_data(paths, flags);
	return (0);
}

void	read_info(char **paths, t_flags *flags)
{
	DIR	*d;
    int i;
    int len;

    i = 0;
    len = 0;
    while (paths[len]) 
        len++;
    while (paths[i])
    {
	    d = opendir(paths[i]);
	    if (d == NULL)
	    	error_message(paths[i]);
        else {
            if (len > 1) 
            {
                if (i <= len && i > 0)
                    ft_putchar('\n');
                ft_putstr(paths[i]);
	            ft_putstr(":\n");
            }
            if (flags->R == TRUE)
                ft_putendl("flag implementation not done yet R");
            if (flags->a == TRUE)
                display_ls_noflag(d, flags);
            if (flags->l == TRUE)
                ft_putendl("flag implementation not done yet l");
            if (flags->r == TRUE)
                ft_putendl("flag implementation not done yet r");
            if (flags->t == TRUE)
                ft_putendl("flag implementation not done yet t");
            display_ls_noflag(d, flags);
        }
        i++;
    }
}

void    display_mode(struct dirent *dir, t_flags *flags, int i)
{
    if (flags->a == TRUE || flags->f == TRUE)
    {
		if (i > 0)
			ft_putstr("\t\t");
		ft_putstr(dir->d_name);
    }
    else
    {
        if (dir->d_name[0] != '.')
		{
			if (i > 0)
				ft_putstr("\t\t");
			ft_putstr(dir->d_name);
		}
    }
}

void	display_ls_noflag(DIR *d, t_flags *flags)
{
	struct dirent	*dir;
	int				i;

	dir = readdir(d);
    i = 0;
	while (dir)
	{
        display_mode(dir, flags, i);
		dir = readdir(d);
        i++;
	}
	ft_putchar('\n');
}

void	error_message(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": No such file or directory\n");
}
