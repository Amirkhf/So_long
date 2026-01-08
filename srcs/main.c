/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:35:43 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/08 20:39:11 by amkhelif         ###   ########.fr       */
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
		mlx_loop(all.window.mlx);
	}
	return (1);
}

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