/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:05:21 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/08 20:48:39 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx_game(t_game *g)
{
	g->init = mlx_init((g->width - 1) * PIXEL,
			g->height * PIXEL, "so_long", false);
	if (!g->init)
		print_error("Error initializing MLX game");
	set_textures(g);
	put_textures(g);
	mlx_key_hook(g->init, &set_moves, g);
	mlx_loop(g->init);
}
