/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:33:24 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/13 15:56:29 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_file(argv[1]) == 1 && check_map_size(argv[1]) == 1)
			create_game(argv[1]);
		else
			print_error("Wrong map");
	}
	else
		return (0);
}
