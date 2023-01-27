/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwnam <ngw7617@student.42seoul.k>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:41:02 by gwnam             #+#    #+#             */
/*   Updated: 2022/10/01 17:37:18 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_func(char a, char b, char c, char d)
{
	char	space;
	char	comma;

	space = ' ';
	comma = ',';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &space, 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a == '9' && b == '8' && c == '9' && d == '9')
	{
	}
	else
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}

void	compare_func(char a, char b, char c, char d)
{
	if (a < c)
	{
		write_func(a, b, c, d);
	}
	else if (a == c)
	{
		if (b < d)
		{
			write_func(a, b, c, d);
		}
	}
}

void	rep_mini_func(char a, char b, char c, char d)
{
	while (c <= '9')
	{
		while (d <= '9')
		{
			compare_func(a, b, c, d);
			d++;
		}
		d = '0';
		c++;
	}
	c = '0';
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	d = '0';
	while (a <= '9')
	{
		while (b <= '9')
		{
			rep_mini_func(a, b, c, d);
			b++;
		}
		b = '0';
		a++;
	}
}
