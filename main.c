/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:04:49 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/24 07:34:58 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_srcs/so_long.h"

int	main(int argc, char **argv)
{
	t_pars	var;
	t_data	data;

	var.args = argc;
	var.map_path = argv[1];
	data.width = 64;
	ft_check_path_errors(&var);
	ft_check_map_errors(&var);
	ft_mlx(&var, &data);
	return (0);
}
