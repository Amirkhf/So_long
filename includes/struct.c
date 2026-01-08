/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:58:40 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/08 15:18:21 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	*initialise_img(t_all *all, char *str)
{
	return (mlx_xpm_file_to_image(all->window.mlx, str, &all->images.width,
			&all->images.height));
}

void	struct_all(t_all *all, char *str)
{
	all->window.mlx = mlx_init();
	all->window.map = read_map(str, all->window.map);
	all->messure.len_line = ft_strlen(all->window.map[0]);
	all->messure.nb_line = ft_nb_line(all->window.map);
	all->window.mlx_win = mlx_new_window(all->window.mlx, all->messure.len_line
			* 96, all->messure.nb_line * 96, "ntm");
	all->images.collect = initialise_img(all, "img/collect.xpm");
	all->images.ennemy = initialise_img(all, "img/ennemy.xpm");
	all->images.exit = initialise_img(all, "img/exit.xpm");
	all->images.ground = initialise_img(all, "img/ground.xpm");
	all->images.player = initialise_img(all, "img/player.xpm");
	all->images.wall_down_left = initialise_img(all, "img/wall_down_left.xpm");
	all->images.wall_down_right = initialise_img(all,
			"img/wall_down_right.xpm");
	all->images.wall_down = initialise_img(all, "img/wall_down.xpm");
	all->images.wall_down_v1 = initialise_img(all, "img/wall_down_v1.xpm");
	all->images.wall_down_v2 = initialise_img(all, "img/wall_down_v2.xpm");
	all->images.wall_left = initialise_img(all, "img/wall_left.xpm");
	all->images.wall_middle_v1 = initialise_img(all, "img/wall_middle_v1.xpm");
	all->images.wall_middle_v2 = initialise_img(all, "img/wall_middle_v2.xpm");
	all->images.wall_middle_v3 = initialise_img(all, "img/wall_middle_v3.xpm");
	all->images.wall_middle = initialise_img(all, "img/wall_middle.xpm");
	all->images.wall_right = initialise_img(all, "img/wall_right.xpm");
	all->images.wall_top_left = initialise_img(all, "img/wall_top_left.xpm");
	all->images.wall_top_right = initialise_img(all, "img/wall_top_right.xpm");
	all->images.wall_top_shark = initialise_img(all, "img/wall_top_shark.xpm");
	all->images.wall_top = initialise_img(all, "img/wall_top.xpm");
	all->messure.nb_collect = ft_nb_collect(all->window.map);
}

void	struct_count(t_count *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->j = 0;
	data->i = 0;
}