/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukwak <jukwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:07:46 by jukwak            #+#    #+#             */
/*   Updated: 2022/10/20 11:35:04 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	bsq_fun(t_type *map_info, t_pair *nxny)
{
	int	**xy;

	nxny->y = map_info->num;
	xy = xy_setting(nxny->x, nxny->y);
	xy = setting_o(map_info->map, xy, *nxny, &(map_info->eof[1]));
	xy = xy_first_line(nxny->x, nxny->y, xy);
	xy = get(xy, nxny->x, nxny->y);
	print_max_map(map_info, xy, nxny->x, nxny->y);
}

t_pair	find_max_loc(int **xy, int nx, int ny)
{
	int		t;
	int		t2;
	t_pair	loc;

	loc.size = 0;
	t = -1;
	while (++t < ny)
	{
		t2 = -1;
		while (++t2 < nx)
		{
			if (xy[t][t2] > loc.size)
			{
				loc.size = xy[t][t2];
				loc.x = t2;
				loc.y = t;
			}
		}
	}
	ft_free_xy(xy, ny);
	return (loc);
}

char	**change_max_map(char **map, char eof[3], t_pair loc)
{
	int	temp2;
	int	temp;

	temp = loc.size + 1;
	while (--temp > 0)
	{
		temp2 = loc.size + 1;
		while (--temp2 > 0)
			map[loc.y - temp + 1][loc.x - temp2 + 1] = eof[2];
	}
	return (map);
}

void	print_max_map(t_type *map_info, int **xy, int nx, int ny)
{
	int	temp;
	int	temp2;

	map_info->map = change_max_map(map_info->map,
			map_info->eof, find_max_loc(xy, nx, ny));
	temp = -1;
	while (++temp < ny)
	{
		temp2 = -1;
		while (++temp2 < nx)
		{
			write(1, &(map_info->map[temp][temp2]), 1);
		}
		write(1, "\n", 1);
	}
}
