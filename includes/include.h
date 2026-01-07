/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:34:17 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/07 18:27:48 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_count
{
	int		e;
	int		c;
	int		p;
	int		i;
	int		j;
}			t_count;

typedef struct s_position
{
	int		x;
	int		y;
}			p_position;

int			check_map(char *str);
int			check_name(char *str);
char		*ft_itoa(int n);
void		free_function(char **str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
int			check_ennemy(char **map, p_position *position);
int			count_elements(char **map);
int			check_character(char **map);
int			check_name(char *str);
void		struct_count(t_count *data);
char		**ft_split(char const *s, char c);
char		**read_map(char *str, char **map);
p_position	player_position(char **map);
int			check_wall(char **map);
int			check_wall_top(char *str);
int			check_rectangular(char **map, int len);
void		dfs(char **map, int x, int y);
int			verif_path(char **map);
int			ft_nb_line(char **map);

#endif