/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:22:05 by amkhelif          #+#    #+#             */
/*   Updated: 2026/01/01 13:48:09 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int	main(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc != 2)
		return (0);
	else
	{
		if (parsing(argv[1], map))
		{
			return (write(1, "Error\n", 6), 0);
		}
	}
	return (0);
}
