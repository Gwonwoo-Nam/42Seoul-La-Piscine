/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukwak <jukwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:57:59 by jukwak            #+#    #+#             */
/*   Updated: 2022/10/20 11:35:09 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**get(int **xy, int nx, int ny)
{
	int	x;
	int	y;

	y = 0;
	while (++y < ny)
	{
		x = 0;
		while (++x < nx)
		{
			if (xy[y][x] == 0)
				continue ;
			xy[y][x] = min(xy[y][x - 1], xy[y - 1][x], xy[y - 1][x - 1]) + 1;
		}
	}
	return (xy);
}

int	**xy_setting(int nx, int ny)
{
	int	temp;
	int	**arr;
	int	temp2;

	arr = (int **) malloc (sizeof(int *) * ny);
	temp = -1;
	while (++temp < ny)
	{
		arr[temp] = (int *) malloc (sizeof(int) * nx);
		temp2 = -1;
		while (++temp2 < nx)
			arr[temp][temp2] = -1;
	}
	temp = -1;
	return (arr);
}

int	**xy_first_line(int nx, int ny, int **xy)
{
	int	temp;

	temp = -1;
	while (++temp < ny)
	{
		if (xy[temp][0] != 0)
			xy[temp][0] = 1;
	}
	temp = -1;
	while (++temp < nx)
	{
		if (xy[0][temp] != 0)
			xy[0][temp] = 1;
	}
	return (xy);
}

int	**setting_o(char **map, int **xy, t_pair nxny, char eof[1])
{
	int	t1;
	int	t2;
	int	nx;
	int	ny;

	nx = nxny.x;
	ny = nxny.y;
	t1 = -1;
	while (++t1 < ny)
	{
		t2 = -1;
		while (++t2 < nx)
		{
			if (map[t1][t2] == eof[0])
				xy[t1][t2] = 0;
		}
	}
	return (xy);
}

int	main(int argc, char **argv)
{
	t_type	map_info;
	t_pair	nxny;
	int		i;
	int		rc[2];

	i = 0;
	while (++i < argc)
	{
		nxny.x = 0;
		rc[0] = 0;
		rc[1] = 0;
		if (ft_read_map(&map_info, argv[i], &nxny.x, rc) == 0)
		{
			if (map_info.map == NULL)
				return (0);
			bsq_fun(&map_info, &nxny);
			ft_free_mem(&map_info, &rc[1]);
		}
		else
		{
			write(1, "map error\n", 10);
		}	
	}
	return (0);
}
