/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:59:29 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/08 15:11:51 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

// verifie si dans la direction ou il va
// ces un mur ou une sortie mes quil a
// pas tout collecter
// verifie si ces un collectible si ouui on mes
// '0' dans la map est on enleve 1 a la variable
// nb_collect
// enfin on remplace sa postion par un sol
// sa direction par lui
// on mes a jour la position du jouer
void	move_player_top(t_all *all)
{
	int	x;
	int	y;

	x = all->player_position.x;
	y = all->player_position.y;
	if (verif_move_player(all, 1))
		return ;
	else if (its_collect(all, 1))
	{
		all->window.map[x - 1][y] = '0';
		all->messure.nb_collect--;
	}
	finish_game(all, x - 1, y);
	print_img(all, all->images.ground, x, y);
	print_img(all, all->images.player, x - 1, y);
	all->player_position.x -= 1;
}

void	move_player_down(t_all *all)
{
	int	x;
	int	y;

	x = all->player_position.x;
	y = all->player_position.y;
	if (verif_move_player(all, 2))
		return ;
	else if (its_collect(all, 2))
	{
		all->window.map[x + 1][y] = '0';
		all->messure.nb_collect--;
	}
	finish_game(all, x + 1, y);
	print_img(all, all->images.ground, x, y);
	print_img(all, all->images.player, x + 1, y);
	all->player_position.x += 1;
}

void	move_player_left(t_all *all)
{
	int	x;
	int	y;

	x = all->player_position.x;
	y = all->player_position.y;
	if (verif_move_player(all, 3))
		return ;
	else if (its_collect(all, 3))
	{
		all->window.map[x][y - 1] = '0';
		all->messure.nb_collect--;
	}
	finish_game(all, x, y - 1);
	print_img(all, all->images.ground, x, y);
	print_img(all, all->images.player, x, y - 1);
	all->player_position.y -= 1;
}

void	move_player_right(t_all *all)
{
	int	x;
	int	y;

	x = all->player_position.x;
	y = all->player_position.y;
	if (verif_move_player(all, 4))
		return ;
	else if (its_collect(all, 4))
	{
		all->window.map[x][y + 1] = '0';
		all->messure.nb_collect--;
	}
	finish_game(all, x, y + 1);
	print_img(all, all->images.ground, x, y);
	print_img(all, all->images.player, x, y + 1);
	all->player_position.y += 1;
}
