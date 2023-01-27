/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwnam <gwnam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 08:57:33 by gwnam             #+#    #+#             */
/*   Updated: 2022/10/20 11:39:28 by gwnam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pair
{
	int	size;
	int	x;
	int	y;
}	t_pair;

typedef struct s_type
{
	int		num;
	char	eof[3];
	char	**map;
}	t_type;

int		**get(int **xy, int nx, int ny);
int		**xy_setting(int nx, int ny);
int		**xy_first_line(int nx, int ny, int **xy);
int		**setting_o(char **map, int **xy, t_pair nxny, char eof[1]);
t_pair	find_max_loc(int **xy, int nx, int ny);
char	**change_max_map(char **map, char eof[3], t_pair loc);
void	print_max_map(t_type *map_info, int **xy, int nx, int ny);
int		check_map_char(char map, char *eof);
int		check_eof(char *eof);
int		ft_check_eof(char *eof, int *fd_long, char *c);
int		ft_alloc_line(char *map, char eof[], int *fd_long, int line_len_count);
int		ft_read_line(t_type *map_info, int *fd,
			int *base_len_count, int rc[]);
void	fd_close(int *fd_short, int *fd_long);
void	ft_count_linenum(int num, int *cnt);
int		ft_read_firstline(int *fd_short, char *c, int *first_line_len);
int		ft_check_linenum(int *num, int *fd_long, char *c, int first_line_len);
int		ft_read_map(t_type *map_info, char *argv,
			int *base_len_count, int rc[]);
int		min(int a, int b, int c);
void	ft_print_map(char **map);
void	bsq_fun(t_type *map_info, t_pair *nxny);
void	ft_free_mem(t_type *map_info, int *rc);
void	ft_free_xy(int **xy, int r);

#endif
