/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:09:37 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:00 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int	get_digit_power(int number)
{
	int	i;

	i = 1;
	while (number)
	{
		i *= 10;
		number /= 10;
	}
	return (i / 10);
}

void	ft_write_int(int number)
{
	int		power;
	char	digit;

	if (!number)
	{
		write(1, "0\n", 2);
		return ;
	}
	power = get_digit_power(number);
	while (power)
	{
		digit = number / power + '0';
		write(1, &digit, 1);
		number = number % power;
		power /= 10;
	}
	write(1, "\n", 1);
}

void	ft_write_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_write_string(par[i].str);
		ft_write_int(par[i].size);
		ft_write_string(par[i].copy);
		i++;
	}
}
