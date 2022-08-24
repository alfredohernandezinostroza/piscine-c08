/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:23:35 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/24 16:04:09 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_copy_str(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	char				**strings;
	struct s_stock_str	*converted_strs;
	int					i;
	int					size;

	converted_strs = malloc(sizeof(t_stock_str) * (ac + 1));
	strings[ac] = 0;
	i = 0;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		converted_strs[i].size = size;
		converted_strs[i].str = malloc(sizeof(char) * size);
		converted_strs[i].copy = malloc(sizeof(char) * size);
		ft_copy_str(converted_strs[i].str, av[i]);
		ft_copy_str(converted_strs[i].copy, av[i]);
		i++;
	}
	return (strings);
}
