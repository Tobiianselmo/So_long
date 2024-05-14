/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:38:36 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/01 15:52:04 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->height > y)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	quantity_item(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->height > y)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (check_item_pos(game, y, x) == 1)
				x++;
			else
				print_error("Unrecognizable item");
		}
		y++;
	}
}
