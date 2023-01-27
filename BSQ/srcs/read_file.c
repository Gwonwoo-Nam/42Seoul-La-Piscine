/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwnam <gwnam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:39:53 by gwnam             #+#    #+#             */
/*   Updated: 2022/10/20 12:38:53 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_map_char(char map, char *eof)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (map == eof[i])
			return (0);
		i++;
	}
	return (-1);
}

int	ft_alloc_line(char *map, char eof[], int *fd, int line_len_count)
{
	int		j;
	char	c;

	j = 0;
	while (j < line_len_count)
	{
		read(fd[1], &c, 1);
		if (check_map_char(c, eof) == -1)
			return (-1);
		map[j] = c;
		j++;
	}
	map[j] = '\0';
	read(fd[1], &c, 1);
	return (0);
}

int	ft_read_line(t_type *map_info, int *fd, int *base_len_count, int *rc)
{
	char	c_pastc[2];

	while (read(fd[0], &c_pastc[0], 1) && rc[0] < map_info->num)
	{
		if (c_pastc[0] != '\n')
			rc[1]++;
		else
		{
			if (rc[0] == 0)
				*base_len_count = rc[1];
			if (rc[0] != 0 && *base_len_count != rc[1])
				return (-1);
			map_info->map[rc[0]] = (char *)malloc(sizeof(char) * (rc[1] + 1));
			if (!&map_info->map[rc[0]] || ft_alloc_line
				(map_info->map[rc[0]], map_info->eof, fd, rc[1]) == -1)
				return (-1);
			rc[0]++;
			rc[1] = 0;
		}
		c_pastc[1] = c_pastc[0];
	}
	if (c_pastc[1] != '\n')
		return (-1);
	return (0);
}

int	ft_read_map(t_type *map_info, char *argv, int *base_len_count, int *rc)
{
	int		fd[2];
	char	c;
	int		first_line_len;
	int		flag;

	flag = 0;
	fd[0] = open(argv, O_RDWR);
	if (fd[0] == -1)
	{
		close(fd[0]);
		return (-1);
	}
	fd[1] = open(argv, O_RDWR);
	flag += ft_read_firstline(fd, &c, &first_line_len);
	flag += ft_check_linenum(&map_info->num, fd, &c, first_line_len);
	map_info->map = (char **)malloc(sizeof(char *) * (map_info->num));
	flag += ft_check_eof(map_info->eof, fd, &c);
	flag += ft_read_line(map_info, fd, base_len_count, rc);
	if (flag != 0 || *base_len_count == 0)
	{
		fd_close(&fd[0], &fd[1]);
		return (-1);
	}
	return (0);
}
