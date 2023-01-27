/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwnam <gwnam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:52:14 by gwnam             #+#    #+#             */
/*   Updated: 2022/10/20 12:34:50 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	fd_close(int *fd_short, int *fd_long)
{
	close(*fd_short);
	close(*fd_long);
}

int	ft_read_firstline(int *fd, char *c, int *first_line_len)
{
	*first_line_len = 0;
	while (read(fd[0], c, 1) && *c != '\n')
	{
		*first_line_len = *first_line_len + 1;
	}
	if (*first_line_len < 4)
		return (-1);
	return (0);
}

int	ft_check_linenum(int *num, int *fd, char *c, int first_line_len)
{
	int	cnt;

	cnt = 0;
	*num = 0;
	while (cnt < first_line_len - 3)
	{
		if (read(fd[1], c, 1) && (*c <= '9' && *c >= '0'))
		{
			*num = (*num) * 10 + *c - '0';
			cnt++;
		}
		else
			return (-1);
	}
	read(fd[1], c, 1);
	return (0);
}

int	eof_same_char(char *eof)
{
	if (eof[0] == eof[1] || eof[0] == eof[2] || eof[1] == eof[2])
		return (-1);
	return (0);
}

int	ft_check_eof(char *eof, int *fd, char *c)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (*c >= 32 && *c <= 126)
		{
			eof[i] = *c;
		}
		else
			return (-1);
		read(fd[1], c, 1);
		i++;
	}
	if (*c != '\n' || eof_same_char(eof) == -1)
		return (-1);
	return (0);
}
