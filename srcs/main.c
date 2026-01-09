/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:35:43 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 13:01:05 by amkhelif         ###   ########.fr       */
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
		mlx_loop_hook(all.window.mlx, timer, &all);
		mlx_loop(all.window.mlx);
	}
	return (1);
}

void	finish_game(t_all *all, int x, int y)
{
	if (all->window.map[x][y] == 'E' && all->messure.nb_collect == 0)
		exit(0);
}