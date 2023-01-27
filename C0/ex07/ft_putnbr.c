/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwnam <gwnam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:38:35 by gwnam             #+#    #+#             */
/*   Updated: 2022/10/01 11:59:28 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur(int nb)
{
	char	remainder;

	if (nb > 0)
	{
		recur(nb / 10);
		remainder = (nb % 10) + '0';
		write(1, &remainder, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		write(1, "147483648", 9);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		recur(-nb);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		recur(nb);
	}
}
