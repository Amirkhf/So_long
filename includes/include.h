/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:34:17 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/08 20:42:46 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define W 119
# define S 115
# define A 97
# define D 100
# define TOP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define ESC 65307

typedef struct s_messure
{
	int			len_line;
	int			nb_line;
	int			nb_collect;
}				p_messure;

typedef struct s_count
{
	int			e;
	int			c;
	int			p;
	int			i;
	int			j;
}				t_count;

typedef struct s_position
{
	int			x;
	int			y;
}				p_position;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
}				p_game;

typedef struct s_images
{
	int			count_collect;
	int			nb_collect;
	int			count_move;
	int			width;
	int			height;
	void		*collect;
	void		*ennemy;
	void		*exit;
	void		*ground;
	void		*player;
	void		*wall_down_left;
	void		*wall_down_right;
	void		*wall_down;
	void		*wall_down_v1;
	void		*wall_down_v2;
	void		*wall_left;
	void		*wall_middle_v1;
	void		*wall_middle_v2;
	void		*wall_middle_v3;
	void		*wall_middle;
	void		*wall_right;
	void		*wall_top_left;
	void		*wall_top_right;
	void		*wall_top_shark;
	void		*wall_top;
}				p_images;

typedef struct s_all
{
	p_images	images;
	p_position	player_position;
	p_game		window;
	p_messure	messure;
}				t_all;

void			draw_wall_middle(t_all *all, int len_line, int j, char *str);
void			draw_map(t_all *all);
void			draw_wall(t_all *all);
void			random_wall_middle(t_all *all, int i, int j);
void			draw_wall_top(t_all *all, int len_line, char *str);
void			print_ramdom_wall_top(t_all *all, int i, int j);
void			print_img(t_all *all, void *img, int i, int j);
void			draw_wall_down(t_all *all, int len_line, int nb_line,
					char *str);
void			take_collect(t_all *all);
int				nb_collect(t_all *all);
void			move(t_all *all);
int				ft_nb_collect(char **map);
int				check_map(char *str);
int				check_name(char *str);
char			*ft_itoa(int n);
void			free_function(char **str);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);
int				check_ennemy(char **map, p_position *position);
int				count_elements(char **map);
int				check_character(char **map);
int				check_name(char *str);
void			struct_count(t_count *data);
char			**ft_split(char const *s, char c);
char			**read_map(char *str, char **map);
p_position		player_position(char **map);
int				check_wall(char **map);
int				check_wall_top(char *str);
int				check_rectangular(char **map, int len);
void			dfs(char **map, int x, int y);
int				verif_path(char **map);
int				ft_nb_line(char **map);
void			*initialise_img(t_all *all, char *str);
void			struct_all(t_all *all, char *str);
void			print_img(t_all *all, void *img, int i, int j);
void			draw_ground(t_all *all);
void			draw_exit(t_all *all);
void			draw_player(t_all *all);
void			draw_collectible(t_all *all);
void			draw_ennemy(t_all *all);

void			move_player_top(t_all *all);
void			move_player_left(t_all *all);
void			move_player_right(t_all *all);
int				verif_direction(t_all *all, int x, int y);
int				verif_move_player(t_all *all, int move);
int				its_collect(t_all *all, int move);
void			finish_game(t_all *all, int x, int y);
int				move_player(int direction, t_all *all);
void			move_player_down(t_all *all);

#endif