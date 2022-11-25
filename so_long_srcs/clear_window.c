/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:59:49 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/22 01:48:43 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_clear_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	exit(EXIT_FAILURE);
}
