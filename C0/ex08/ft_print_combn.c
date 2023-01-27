/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwnam <gwnam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:19:04 by gwnam             #+#    #+#             */
/*   Updated: 2022/10/04 14:52:02 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	power(int a, int n)
{
	int	k;

	k = 1;
	while (k < n)
	{
		a = 10 * a;
		k++;
	}
	return (a);
}

void	putnbr(int n, int R[])
{
	int	k;
	int	a;

	k = 0;
	while (k < n)
	{
		a = R[k] + '0';
		write(1, &a, 1);
		k++;
	}
}

void	save_digits(int n, int num, int R[])
{
	if (n >= 0)
	{
		save_digits(n - 1, num / 10, R);
		R[n - 1] = (num % 10);
	}
}

int	valid_check(int n, int R[])
{
	int	m;
	int	iter;
	int	k;

	m = 0;
	iter = 0;
	k = 0;
	while (iter < n - 1)
	{
		if (R[iter] < R[iter + 1])
			m += 1;
		iter++;
	}
	return (m);
	m = 0;
}

void	ft_print_combn(int n)
{
	int			num;
	char		comma;
	char		space;
	static int	r[9];
	int			first;

	comma = ',';
	space = ' ';
	num = 0;
	first = 0;
	while ((num < power(10, n)) & (num < 123456790))
	{
		save_digits(n, num, r);
		if (valid_check(n, r) == (n - 1))
		{
			if (first > 0)
			{	
				write(1, &comma, 1);
				write(1, &space, 1);
			}
			putnbr(n, r);
			first++;
		}
		num++;
	}
}
