/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:15:59 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/09 19:02:57 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures(t_game *game)
{
	game->texture = mlx_load_png("images/player64.png");
	if (!game->texture)
		print_error("Error: loading player texture");
	game->img_p = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("images/wallboca.png");
	if (!game->texture)
		print_error("Error loading wall texture");
	game->img_w = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("images/collect64.png");
	if (!game->texture)
		print_error("Error loading collectable texture");
	game->img_c = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("images/new_exit64.png");
	if (!game->texture)
		print_error("Error loading exit texture");
	game->img_e = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("images/grass.png");
	if (!game->texture)
		print_error("Error loading floor texture");
	game->img_f = mlx_texture_to_image(game->init, game->texture);
	mlx_delete_texture(game->texture);
}

void	put_textures(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	put_floor(game);
	while (game->height > y)
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->init, game->img_w,
					x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->init, game->img_c,
					x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->init, game->img_e,
					x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->init, game->img_p,
		game->x * PIXEL, game->y * PIXEL);
}

void	put_floor(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->height > y)
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			mlx_image_to_window(game->init, game->img_f,
				x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}
