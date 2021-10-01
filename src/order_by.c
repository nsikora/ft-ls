/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_by.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:38:30 by nsikora           #+#    #+#             */
/*   Updated: 2021/10/01 18:20:59 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ls.h"

void	swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int	get_str_nb(char **str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	order_by_alphabetical(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < get_str_nb(str) - 1)
	{
		while (j < (int)ft_strlen(str[i]) + 1
			&& j < (int)ft_strlen(str[i + 1]) + 1)
		{
			if (str[i][j] != str[i + 1][j] && str[i][j] > str[i + 1][j])
			{
				swap(&str[i], &str[i + 1]);
				i = -1;
				break ;
			}
			if (str[i][j] != str[i + 1][j] && str[i][j] < str[i + 1][j])
				break ;
			j++;
		}
		i++;
		j = 0;
	}
}
