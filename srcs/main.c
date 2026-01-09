/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:35:43 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 16:32:56 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc == 2)
	{
		if (check_map(argv[1]))
			return (write(1, "Error\n", 6), 0);
		struct_all(&all, argv[1]);
		draw_map(&all);
		mlx_key_hook(all.window.mlx_win, move_player, &all);
		mlx_loop_hook(all.window.mlx, boucle_play, &all);
		mlx_loop(all.window.mlx);
	}
	return (1);
}

int	boucle_play(t_all *all)
{
	timer(all);
	verif_player_safe(all);
	// select_collectible(all);
	return (0);
}

int	verif_player_safe(t_all *all)
{
	if (all->window.map[all->player_position.x][all->player_position.y
		+ 1] == 'X'
		|| all->window.map[all->player_position.x][all->player_position.y
		- 1] == 'X' || all->window.map[all->player_position.x
		+ 1][all->player_position.y] == 'X'
		|| all->window.map[all->player_position.x
		- 1][all->player_position.y] == 'X')
	{
		exit(0);
	}
	return (0);
}

void	finish_game(t_all *all, int x, int y)
{
	if (all->window.map[x][y] == 'E' && all->messure.nb_collect == 0)
		exit(0);
}