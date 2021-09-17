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

void	read_info(char *path, int flagAvailable);
void	display_ls_noflag(DIR *d);
void	error_message(char *path);
char	**initialize_paths(char **av);

#endif
