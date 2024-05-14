/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:46:09 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/08 20:37:14 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'F'
				&& map[y][x] != '\n')
				print_error("Invalid map");
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game, int y, int x)
{
	if (game->dup[y][x] == '1' || game->dup[y][x] == 'F')
		return ;
	game->dup[y][x] = 'F';
	flood_fill(game, y - 1, x);
	flood_fill(game, y + 1, x);
	flood_fill(game, y, x - 1);
	flood_fill(game, y, x + 1);
}
