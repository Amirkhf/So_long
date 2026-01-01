#ifndef INCLUDE_H
# define INCLUDE_H

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

typedef struct s_images
{
	void	*Wall;
	void	*player;
	void	*ground;
	void	*collectable;
}			t_images;

typedef struct s_position
{
	int		y;
	int		x;
}			t_position;
int			nb_ligne(char **map);
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