/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwnam <ngw7617@student.42seoul.k>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:23:30 by gwnam             #+#    #+#             */
/*   Updated: 2022/10/01 21:56:40 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_comma(char a, char b, char c)
{
	char	space;
	char	comma;

	space = ' ';
	comma = ',';
	if (a != b && b != c && a != c)
	{
		if (a < b && b < c)
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, &c, 1);
			if (a != '7' | b != '8' | c != '9')
			{
				write(1, &comma, 1);
				write(1, &space, 1);
			}
		}
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '0';
	c = '0';
	while (a <= '7')
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				write_comma(a, b, c);
				c++;
			}
			c = '0';
			b++;
		}
		b = '0';
		a++;
	}
}
