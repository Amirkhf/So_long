/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:59:29 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/08 20:40:06 by amkhelif         ###   ########.fr       */
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
	if (verif_move_player(all, 1) == 1)
		return ;
	else if (its_collect(all, 1))
	{
		printf("c un collecitble\n");
		all->window.map[all->player_position.x
			- 1][all->player_position.y] = '0';
		all->messure.nb_collect--;
		take_collect(all);
	}
	finish_game(all, all->player_position.x - 1, all->player_position.y);
	print_img(all, all->images.ground, all->player_position.y,
		all->player_position.x);
	print_img(all, all->images.player, all->player_position.y,
		all->player_position.x - 1);
	all->player_position.x -= 1;
	move(all);
}

void	move_player_down(t_all *all)
{
	if (verif_move_player(all, 2))
	{
		printf("pas bon move player down\n");
		return ;
	}
	else if (its_collect(all, 2))
	{
		printf("c un collecitble\n");
		all->window.map[all->player_position.x
			+ 1][all->player_position.y] = '0';
		all->messure.nb_collect--;
		take_collect(all);
	}
	finish_game(all, all->player_position.x + 1, all->player_position.y);
	print_img(all, all->images.ground, all->player_position.y,
		all->player_position.x);
	print_img(all, all->images.player, all->player_position.y,
		all->player_position.x + 1);
	all->player_position.x += 1;
	move(all);
}

void	move_player_left(t_all *all)
{
	if (verif_move_player(all, 3))
	{
		printf("pas bon move player left\n");
		return ;
	}
	else if (its_collect(all, 3))
	{
		printf("c un collecitble\n");
		all->window.map[all->player_position.x][all->player_position.y
			- 1] = '0';
		all->messure.nb_collect--;
		take_collect(all);
	}
	finish_game(all, all->player_position.x, all->player_position.y - 1);
	print_img(all, all->images.ground, all->player_position.y,
		all->player_position.x);
	print_img(all, all->images.player, all->player_position.y - 1,
		all->player_position.x);
	all->player_position.y -= 1;
	move(all);
}

void	move_player_right(t_all *all)
{
	if (verif_move_player(all, 4))
	{
		printf("pas bon move player right\n");
		return ;
	}
	else if (its_collect(all, 4))
	{
		printf("c un collecitble\n");
		all->window.map[all->player_position.x][all->player_position.y
			+ 1] = '0';
		all->messure.nb_collect--;
		take_collect(all);
	}
	finish_game(all, all->player_position.x, all->player_position.y + 1);
	print_img(all, all->images.ground, all->player_position.y,
		all->player_position.x);
	print_img(all, all->images.player, all->player_position.y + 1,
		all->player_position.x);
	all->player_position.y += 1;
	move(all);
}
