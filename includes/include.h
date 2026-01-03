#ifndef INCLUDE_H
# define INCLUDE_H

# include "../minilibx-linux/mlx.h"
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

typedef struct s_map
{
	int		len_line;
	int		nb_line;
}			t_map;

typedef struct s_play
{
	int		i;
	int		j;
	int		width;
	int		height;
	void	*exit;
	void	*mlx;
	void	*mlx_win;
	void	*collectible;
	void	*player;
	void	*ground;
	void	*wall_top_right;
	void	*wall_top_left;
	void	*wall_top;
	void	*wall_down_left;
	void	*wall_down_right;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	void	*wall_middle;
}			t_play;

// typedef struct s_images
// {
// 	void	*Wall;
// 	void	*player;
// 	void	*ground;
// 	void	*collectible;

// }			t_images;

typedef struct s_position
{
	int		y;
	int		x;
}			t_position;

void		struct_map(t_map *map, char **str);
void		draw_collectible(t_play *play, char **map);
void		draw_exit(t_play *play, char **map);
void		draw_ground(t_play *play, char **map);
void		draw_player(t_play *play, char **map);
void		draw_wall_middle(t_play *play, int i, int j);
void		draw_map(t_play *play, char **map, int len_line);
void		struct_play(t_play *data, t_map *map_size);
void		draw_wall(t_play *play, char **map, int len_line);
void		draw_wall_top(t_play *play, char *str, int len_line);
void		draw_wall_down(t_play *play, char *str, int len_line, int j);
int			ft_nb_line(char **map);
int			verif_path(char **map);
void		dfs(char **map, int x, int y);
t_position	player_position(char **map);
void		struct_position(t_position *position);
int			parsing(char *str, char **map);
int			check_map(char **map);
int			check_name(char *str);
void		free_function(char **str);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
char		**read_map(char *str, char **map);
int			check_rectangular(char **map, int len);
int			check_wall(char **map);
int			count_elements(char **map);
int			check_wall_top(char *str);
int			check_character(char **map);
void		struct_count(t_count *data);

#endif