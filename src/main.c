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
	int		flag_available;
    t_flags *flags;
    char	**paths;

    flag_available = 0;
    if (ac == 1) {
		display_ls_noflag(opendir("."));
        return (0);
    }
	else
	{
        if ((flags = malloc(sizeof(t_flags))) == 0)
		    return (1);
        initialize_flags(flags);
        get_flags(av, flags);
        if (flags->illegal == TRUE) {
            free(flags);
            return (0);
        }
        paths = get_paths(av);
		read_info(paths, flags);
	}
	return (0);
}

void	read_info(char **path, t_flags *flags)
{
	DIR	*d;
    int i;

    // I = 2 FOR OUR TEST. IT WILL NEED TO BE EQUAL TO 0 with the true **path
    i = 0;
    while (path[i]) {
	    d = opendir(path[i]);
	    if (d == NULL)
	    {
	    	error_message(path[i]);
	    	return ;
	    }
        ft_putstr(path[i]);
	    ft_putstr(":\n");
	    if (d)
	    {
            if (flags->R == TRUE)
                ft_putendl("flag implementation not done yet");
            if (flags->a == TRUE)
                ft_putendl("flag implementation not done yet");
            if (flags->f == TRUE)
                ft_putendl("flag implementation not done yet");
            if (flags->l == TRUE)
                ft_putendl("flag implementation not done yet");
            if (flags->r == TRUE)
                ft_putendl("flag implementation not done yet");
            if (flags->t == TRUE)
                ft_putendl("flag implementation not done yet");
            if (flags->empty == TRUE)
                display_ls_noflag(d);
	    }
        i++;
    }
}

void	display_ls_noflag(DIR *d)
{
	struct dirent	*dir;
	int				i;

	dir = readdir(d);
    i = 0;
	while (dir)
	{
		if (dir->d_name[0] != '.')
		{
			if (i > 0)
				ft_putstr("\t\t");
			ft_putstr(dir->d_name);
			i++;
		}
		dir = readdir(d);
	}
	ft_putstr("\n\n");
}

void	error_message(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": No such file or directory\n");
}
