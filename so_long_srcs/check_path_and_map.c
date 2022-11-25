/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_and_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 03:58:27 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/24 13:45:34 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_path_errors(t_pars *var)
{
	int	fd;

	fd = open(var->map_path, O_RDONLY);
	if (var->args != 2)
		ft_print_errors(0);
	else if (fd < 0)
		ft_print_errors(2);
	else if (!(ft_strstr(var->map_path, ".ber")) \
		|| ft_strcmp(ft_strstr(var->map_path, ".ber"), ".ber"))
		ft_print_errors(1);
	close(fd);
}

void	ft_check_map_errors(t_pars *var)
{
	var->coins = 0;
	var->exits = 0;
	var->player = 0;
	ft_lines_count(var);
	ft_read_map(var);
	ft_check_walls(var);
	ft_check_coin_exit_player(var);
}
