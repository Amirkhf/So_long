/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:59:29 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 18:24:41 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player_top(t_all *all)
{
	if (verif_move_player(all, 1, all->player_position.x,
			all->player_position.y) == 1)
		return ;
	else if (its_collect(all, 1, all->player_position.x,
			all->player_position.y))
	{
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
	if (verif_move_player(all, 2, all->player_position.x,
			all->player_position.y))
		return ;
	else if (its_collect(all, 2, all->player_position.x,
			all->player_position.y))
	{
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
	if (verif_move_player(all, 3, all->player_position.x,
			all->player_position.y))
		return ;
	else if (its_collect(all, 3, all->player_position.x,
			all->player_position.y))
	{
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
	if (verif_move_player(all, 4, all->player_position.x,
			all->player_position.y))
		return ;
	else if (its_collect(all, 4, all->player_position.x,
			all->player_position.y))
	{
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
