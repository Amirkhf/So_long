/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:58:40 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 13:38:28 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_all_v2(t_all *all)
{
	all->images.wall_down = initialise_img(all, "img/wall_down.xpm");
	all->images.collect_nb = ft_nb_collect(all->window.map);
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
	all->images.width = 96;
	all->images.height = 96;
	all->images.count_move = 0;
	all->images.count_collect = 0;
	all->images.collect_v1 = initialise_img(all, "img/collect_v1.xpm");
	all->images.collect_v2 = initialise_img(all, "img/collect_v2.xpm");
	all->images.collect_v3 = initialise_img(all, "img/collect_v3.xpm");
	all->images.collect_v4 = initialise_img(all, "img/collect_v4.xpm");
	all->images.collect_v5 = initialise_img(all, "img/collect_v5.xpm");
	all->images.win = initialise_img(all, "img/win.xpm");
}

void	struct_count(t_count *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->j = 0;
	data->i = 0;
}
