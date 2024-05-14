/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:22:20 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/10 12:28:05 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_size(t_game *game, char *argv)
{
	char	*line;
	int		file;

	file = open_file(argv);
	line = get_next_line(file);
	if (!line)
		return ;
	game->height = 1;
	game->width = (int)ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		if (!line)
			return ;
		game->height++;
	}
}

void	get_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return ;
	i = -1;
	while (++i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (i < game->height)
				free_matrix(game->map);
			break ;
		}
		game->map[i] = ft_strdup(line);
		free(line);
	}
	game->map[i] = 0;
}

void	init_struct(t_game *game)
{
	game->collect = 0;
	game->player = 0;
	game->exit = 0;
	game->height = 0;
	game->width = 0;
	game->y = 0;
	game->x = 0;
	game->count = 0;
	game->moves = 0;
}

void	duplicate_map(t_game *game)
{
	int	y;

	y = 0;
	game->dup = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->dup)
		return ;
	while (game->height > y)
	{
		game->dup[y] = ft_strdup(game->map[y]);
		y++;
	}
	game->dup[y] = 0;
}

void	create_game(char *argv)
{
	t_game	game;
	int		file;

	init_struct(&game);
	get_size(&game, argv);
	if ((&game)->height > 21)
		print_error("Invalid map height");
	file = open_file(argv);
	get_map(&game, file);
	check_content(&game);
	get_player_pos(&game);
	duplicate_map(&game);
	flood_fill(&game, (&game)->y, (&game)->x);
	valid_map((&game)->dup);
	init_mlx_game(&game);
	if ((&game)->map)
		free_matrix((&game)->map);
	if ((&game)->dup)
		free_matrix((&game)->dup);
}
