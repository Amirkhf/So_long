/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:08:42 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/02 15:06:51 by amkhelif         ###   ########.fr       */
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

// initialise tout les varibale que jai bessoin pour mon jeux
// fenetre, joueur, mur, sol ..
void	struct_play(t_images *data)
{
	data->j = 0;
	data->i = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "Bonjour");
	data->collectible = mlx_xpm_file_to_image(data->mlx, "images/pieces.xpm",
			&data->width, &data->height);
	data->ground = mlx_xpm_file_to_image(data->mlx, "images/ground.xpm",
			&data->width, &data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm",
			&data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, "images/player.xpm",
			&data->width, &data->height);
	data->Wall = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm",
			&data->width, &data->height);
}