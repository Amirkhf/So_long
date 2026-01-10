/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:11:39 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/10 19:51:32 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*initialise_img(t_all *all, char *str)
{
	return (mlx_xpm_file_to_image(all->window.mlx, str, &all->images.width,
			&all->images.height));
}

void	initialise_variable(t_all *all)
{
	all->images.collect = NULL;
	all->images.collect_v1 = NULL;
	all->images.collect_v2 = NULL;
	all->images.collect_v3 = NULL;
	all->images.collect_v4 = NULL;
	all->images.collect_v5 = NULL;
	all->images.ennemy = NULL;
	all->images.exit = NULL;
	all->images.ground = NULL;
	all->images.player = NULL;
	all->images.wall_down_left = NULL;
	all->images.wall_down_right = NULL;
	all->images.wall_down = NULL;
	all->images.wall_down_v1 = NULL;
	all->images.wall_down_v2 = NULL;
	initialise_variable_v2(all);
}

void	initialise_variable_v2(t_all *all)
{
	all->images.wall_left = NULL;
	all->images.wall_middle_v1 = NULL;
	all->images.wall_middle_v2 = NULL;
	all->images.wall_middle_v3 = NULL;
	all->images.wall_middle = NULL;
	all->images.wall_right = NULL;
	all->images.wall_top_left = NULL;
	all->images.wall_top_right = NULL;
	all->images.wall_top_shark = NULL;
	all->images.wall_top = NULL;
	all->images.game_over = NULL;
	all->images.win = NULL;
	all->images.wall_top_v1 = NULL;
	all->images.wall_top_v2 = NULL;
	all->images.wall_top_v3 = NULL;
	all->images.wall_top_v4 = NULL;
	all->images.wall_top_v5 = NULL;
	all->window.map = NULL;
	all->window.mlx = NULL;
	all->window.mlx_win = NULL;
	all->images.collect_nb = 0;
}

void	struct_all(t_all *all, char *str)
{
	initialise_variable(all);
	all->window.mlx = mlx_init();
	all->window.map = read_map(str, all->window.map);
	all->messure.len_line = ft_strlen(all->window.map[0]);
	all->messure.nb_line = ft_nb_line(all->window.map);
	all->window.mlx_win = mlx_new_window(all->window.mlx, all->messure.len_line
			* 96, all->messure.nb_line * 96, "So_Long");
	all->images.collect = initialise_img(all, "img/collect.xpm");
	all->player_position = player_position(all->window.map);
	all->images.ennemy = initialise_img(all, "img/ennemy.xpm");
	all->images.exit = initialise_img(all, "img/exit.xpm");
	all->images.ground = initialise_img(all, "img/ground.xpm");
	all->images.player = initialise_img(all, "img/player.xpm");
	all->images.wall_down_left = initialise_img(all, "img/wall_down_left.xpm");
	all->images.wall_down_right = initialise_img(all,
			"img/wall_down_right.xpm");
	all->images.game_over = initialise_img(all, "img/game_over.xpm");
	all->images.wall_top_v1 = initialise_img(all, "img/wall_top_v1.xpm");
	all->images.wall_top_v2 = initialise_img(all, "img/wall_top_v2.xpm");
	all->images.wall_top_v3 = initialise_img(all, "img/wall_top_v3.xpm");
	all->images.wall_top_v4 = initialise_img(all, "img/wall_top_v4.xpm");
	all->images.wall_top_v5 = initialise_img(all, "img/wall_top_v5.xpm");
	struct_all_v2(all);
}
