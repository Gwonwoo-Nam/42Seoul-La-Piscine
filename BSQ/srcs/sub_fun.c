/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukwak <jukwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:08:21 by jukwak            #+#    #+#             */
/*   Updated: 2022/10/20 11:35:13 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	min(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a);
}

void	ft_print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		write(1, map[i], j);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_free_mem(t_type *map_info, int *rc)
{
	int	i;

	i = 0;
	while (i < rc[0])
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map);
}

void	ft_free_xy(int **xy, int r)
{
	int	i;

	i = 0;
	while (i < r)
	{
		free(xy[i]);
		i++;
	}
	free(xy);
}
