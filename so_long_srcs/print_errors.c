/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:47:43 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/25 09:53:31 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_errors(int num)
{
	if (num == 0)
		ft_putstr("Error\nThe number of arguments is invalid !!!\n");
	else if (num == 1)
		ft_putstr("Error\nThe file's extension is not correct\n");
	else if (num == 2)
		ft_putstr("Error\nThe file doesn't exist !!!\n");
	else if (num == 3)
		ft_putstr("Error\nThe map is not rectangular !!!\n");
	else if (num == 4)
		ft_putstr("Error\nThe map is not closed !!!\n");
	else if (num == 5)
		ft_putstr("Error\nThe map is not fully surrounded by walls !!!\n");
	else if (num == 6)
		ft_putstr("Error\nThe map is missing an important character !!!\n");
	else if (num == 7)
		ft_putstr("Error\nThe map has a non recognized character !!!\n");
	else if (num == 8)
		ft_putstr("Error\nThe map has duplicates charaters !!!\n");
	else if (num == 9)
		ft_putstr("Error\nThe map is empty !!!\n");
	else if (num == 10)
		ft_putstr("Error\nMlx error !!!\n");
	else if (num == 11)
		ft_putstr("Error\nImage not found\n");
	exit(EXIT_FAILURE);
}
