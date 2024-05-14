/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:03:31 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/09 12:56:48 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_game *game)
{
	mlx_close_window(game->init);
}

void	set_moves(mlx_key_data_t key, void *param)
{
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_window((t_game *)param);
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		mov_up((t_game *)param);
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		mov_down((t_game *)param);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		mov_right((t_game *)param);
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		mov_left((t_game *)param);
}

int	do_moves(t_game *g, int move)
{
	if (move == 1 && g->map[g->y - 1][g->x] != '1')
	{
		g->y--;
		g->img_p->instances[0].y -= PIXEL;
		return (1);
	}
	if (move == 2 && g->map[g->y + 1][g->x] != '1')
	{
		g->y++;
		g->img_p->instances[0].y += PIXEL;
		return (1);
	}
	if (move == 3 && g->map[g->y][g->x + 1] != '1')
	{
		g->x++;
		g->img_p->instances[0].x += PIXEL;
		return (1);
	}
	if (move == 4 && g->map[g->y][g->x - 1] != '1')
	{
		g->x--;
		g->img_p->instances[0].x -= PIXEL;
		return (1);
	}
	return (0);
}
