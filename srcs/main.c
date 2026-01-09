/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:35:43 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/09 18:23:56 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
