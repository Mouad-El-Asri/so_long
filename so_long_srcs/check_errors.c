/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:48:26 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/25 09:53:04 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lines_count(t_pars *var)
{
	char	*line;
	int		fd;
	size_t	lenght;

	fd = open(var->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!(line))
		ft_print_errors(9);
	var->len = ft_strlen(line);
	var->count = 0;
	while (line)
	{
		free(line);
		lenght = ft_strlen(line);
		line = get_next_line(fd);
		if (var->len != lenght)
			ft_print_errors(3);
		var->count++;
	}
	close(fd);
}

void	ft_read_map(t_pars *var)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(var->map_path, O_RDONLY);
	var->lines = malloc(sizeof(char *) * (var->count + 1));
	while (i < var->count)
	{
		var->lines[i] = get_next_line(fd);
		i++;
	}
	var->lines[i] = NULL;
	close(fd);
}

void	ft_check_walls(t_pars *var)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (var->lines[i] && i < var->count)
	{
		j = 0;
		while (var->lines[i][j] && j < var->len)
		{
			if ((var->lines[0][j] != '1') ||
				(var->lines[var->count - 1][j] != '1'))
				ft_print_errors(4);
			if ((var->lines[i][0] != '1') ||
				(var->lines[i][var->len - 1] != '1'))
				ft_print_errors(5);
			j++;
		}
		i++;
	}
}

void	ft_check_coin_exit_player(t_pars *var)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (i < var->count)
	{
		j = 0;
		while (j < var->len)
		{
			c = var->lines[i][j];
			ft_check_characters(c, var);
			j++;
		}
		i++;
	}
	if (var->exits < 1 || var->coins < 1 || var->player < 1)
		ft_print_errors(6);
	else if (var->player > 1)
		ft_print_errors(8);
}

void	ft_check_characters(char c, t_pars *var)
{
	if (c == 'E')
		var->exits++;
	if (c == 'C')
		var->coins++;
	if (c == 'P')
		var->player++;
	if (c != 'C' && c != 'E' && c != 'P' && c != '0' && c != '1')
		ft_print_errors(7);
}
