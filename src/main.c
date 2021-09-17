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
	//char	**paths;
	//char	**flags;
	int		flag_available;
	int		i;

	flag_available = 0;
	i = 1;
	//paths = getPaths();
	//flags = getFlags();
	if (ac == 1)
		read_info(".", flag_available);
	else
	{
		while (i < ac)
		{
			if (i == 1 && av[i][0] == '-')
			{
				flag_available = 1;
			}
			read_info(av[i], flag_available);
			i++;
		}
	}
	return (0);
}

void	read_info(char *path, int flagAvailable)
{
	DIR	*d;

	d = opendir(path);
	if (d == NULL)
	{
		error_message(path);
		return ;
	}
	ft_putstr(path);
	ft_putstr(":\n");
	if (d)
	{
		if (flagAvailable == 0)
			display_ls_noflag(d);
		else
			ft_putendl("flag usage in progress");
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
