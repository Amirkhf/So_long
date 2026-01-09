/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:59:29 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 11:56:35 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	move_player(int direction, t_all *all)
{
	if (direction == W || direction == TOP)
		move_player_top(all);
	else if (direction == S || direction == DOWN)
		move_player_down(all);
	else if (direction == A || direction == LEFT)
		move_player_left(all);
	else if (direction == D || direction == RIGHT)
		move_player_right(all);
	else if (direction == ESC)
		exit(0);
	return (0);
}

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
