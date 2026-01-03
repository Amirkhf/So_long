/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:08:42 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/03 20:27:19 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	struct_count(t_count *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->j = 0;
	data->i = 0;
}
// structure pour lalgo dfs
// elle me sert juste a recuperer est stocker la postion
// du joueur sur la map
void	struct_position(t_position *position)
{
	position->x = 0;
	position->y = 0;
}

void	struct_map(t_map *map, char **str)
{
	map->nb_line = ft_nb_line(str);
	map->len_line = ft_strlen(str[0]);
}

// initialise tout les varibale que jai bessoin pour mon jeux
// fenetre, joueur, mur, sol ..
void	struct_play(t_play *data, t_map *map_size)
{
	data->j = 0;
	data->i = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, map_size->len_line * 96,
			map_size->nb_line * 96, "Bonjour");
	data->player = mlx_xpm_file_to_image(data->mlx, "img/player.xpm",
			&data->width, &data->height);
	data->ground = mlx_xpm_file_to_image(data->mlx, "img/ground.xpm",
			&data->width, &data->height);
	data->wall_top = mlx_xpm_file_to_image(data->mlx, "img/wall_top.xpm",
			&data->width, &data->height);
	data->wall_top_left = mlx_xpm_file_to_image(data->mlx,
			"img/wall_top_left.xpm", &data->width, &data->height);
	data->wall_top_right = mlx_xpm_file_to_image(data->mlx,
			"img/wall_top_right.xpm", &data->width, &data->height);
	data->wall_down = mlx_xpm_file_to_image(data->mlx, "img/wall_down.xpm",
			&data->width, &data->height);
	data->wall_down_left = mlx_xpm_file_to_image(data->mlx,
			"img/wall_down_left.xpm", &data->width, &data->height);
	data->wall_down_right = mlx_xpm_file_to_image(data->mlx,
			"img/wall_down_right.xpm", &data->width, &data->height);
	data->wall_left = mlx_xpm_file_to_image(data->mlx, "img/wall_left.xpm",
			&data->width, &data->height);
	data->wall_right = mlx_xpm_file_to_image(data->mlx, "img/wall_right.xpm",
			&data->width, &data->height);
	data->wall_middle = mlx_xpm_file_to_image(data->mlx, "img/wall_middle.xpm",
			&data->width, &data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm", &data->width,
			&data->height);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "img/collect.xpm",
			&data->width, &data->height);
}
