/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:51:39 by cberganz          #+#    #+#             */
/*   Updated: 2021/12/03 20:16:00 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_that_a_line(char *save)
{
	while (*save)
	{
		if (*save == '\n')
			return (1);
		save++;
	}
	return (0);
}
