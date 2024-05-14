/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:17:11 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/13 15:44:33 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_up(t_game *g)
{
	if (do_moves(g, 1) == 1)
	{
		if (g->map[g->y][g->x] == 'C')
		{
			g->count++;
			g->map[g->y][g->x] = '0';
			mlx_image_to_window(g->init, g->img_f, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_image(g->init, g->img_p);
			g->texture = mlx_load_png("images/player64.png");
			if (!g->texture)
				print_error("loading player texture");
			g->img_p = mlx_texture_to_image(g->init, g->texture);
			mlx_image_to_window(g->init, g->img_p, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_texture(g->texture);
		}
		else if (g->map[g->y][g->x] == 'E' && g->count == g->collect)
		{
			g->moves++;
			ft_printf("Moves: %d\n", g->moves);
			close_window(g);
		}
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
	}
}

void	mov_down(t_game *g)
{
	if (do_moves(g, 2) == 1)
	{
		if (g->map[g->y][g->x] == 'C')
		{
			g->count++;
			g->map[g->y][g->x] = '0';
			mlx_image_to_window(g->init, g->img_f, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_image(g->init, g->img_p);
			g->texture = mlx_load_png("images/player64.png");
			if (!g->texture)
				print_error("loading player texture");
			g->img_p = mlx_texture_to_image(g->init, g->texture);
			mlx_image_to_window(g->init, g->img_p, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_texture(g->texture);
		}
		else if (g->map[g->y][g->x] == 'E' && g->count == g->collect)
		{
			g->moves++;
			ft_printf("Moves: %d\n", g->moves);
			close_window(g);
		}
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
	}
}

void	mov_right(t_game *g)
{
	if (do_moves(g, 3) == 1)
	{
		if (g->map[g->y][g->x] == 'C')
		{
			g->count++;
			g->map[g->y][g->x] = '0';
			mlx_image_to_window(g->init, g->img_f, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_image(g->init, g->img_p);
			g->texture = mlx_load_png("images/player64.png");
			if (!g->texture)
				print_error("loading player texture");
			g->img_p = mlx_texture_to_image(g->init, g->texture);
			mlx_image_to_window(g->init, g->img_p, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_texture(g->texture);
		}
		else if (g->map[g->y][g->x] == 'E' && g->count == g->collect)
		{
			g->moves++;
			ft_printf("Moves: %d\n", g->moves);
			close_window(g);
		}
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
	}
}

void	mov_left(t_game *g)
{
	if (do_moves(g, 4) == 1)
	{
		if (g->map[g->y][g->x] == 'C')
		{
			g->count++;
			g->map[g->y][g->x] = '0';
			mlx_image_to_window(g->init, g->img_f, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_image(g->init, g->img_p);
			g->texture = mlx_load_png("images/player64.png");
			if (!g->texture)
				print_error("loading player texture");
			g->img_p = mlx_texture_to_image(g->init, g->texture);
			mlx_image_to_window(g->init, g->img_p, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_texture(g->texture);
		}
		else if (g->map[g->y][g->x] == 'E' && g->count == g->collect)
		{
			g->moves++;
			ft_printf("Moves: %d\n", g->moves);
			close_window(g);
		}
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
	}
}
