/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:05:18 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/10 12:36:55 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(char *argv)
{
	char	*line;
	int		file;
	size_t	len;

	file = open(argv, O_RDONLY);
	line = get_next_line(file);
	if (!line)
		return (0);
	len = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		if (line)
		{
			if (len != ft_strlen(line))
			{
				if (!(len == (ft_strlen(line) + 1)))
					return (free(line), 0);
			}
			if (len == ft_strlen(line) && !(line[len - 1] == '\n'))
				return (free(line), 0);
		}
	}
	return (1);
}

int	check_file(char	*argv)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(argv);
	if (argv[len - 1] == 'r' && argv[len - 2] == 'e' && argv[len - 3] == 'b'
		&& argv[len - 4] == '.')
		return (1);
	return (0);
}

int	check_item_pos(t_game *game, int y, int x)
{
	if (game->map[y][x] != 'P' && game->map[y][x] != 'C'
		&& game->map[y][x] != 'E' && game->map[y][x] != '1'
		&& game->map[y][x] != '0' && game->map[y][x] != '\n')
		return (0);
	if (game->map[y][x] == 'P')
		game->player++;
	else if (game->map[y][x] == 'C')
		game->collect++;
	else if (game->map[y][x] == 'E')
		game->exit++;
	return (1);
}

int	check_borders(t_game *game, int y, int x)
{
	x = -1;
	y = -1;
	while (++x < game->width - 1)
	{
		if (game->map[0][x] != '1')
			return (0);
		if (game->map[game->height - 1][x] != '1')
			return (0);
	}
	while (++y < game->height)
	{
		if (game->map[y][0] != '1')
			return (0);
		if (game->map[y][game->width - 2] != '1')
			return (0);
	}
	return (1);
}

void	check_content(t_game *game)
{
	quantity_item(game);
	if (game->height < 3 || game->width < 6)
		print_error("Wrong map size");
	if (game->player != 1)
		print_error("Wrong players number");
	if (game->collect < 1)
		print_error("Wrong collectable number");
	if (game->exit != 1)
		print_error("Wrong exit number");
	if (check_borders(game, 0, 0) == 0)
		print_error("Wrong borders");
}
