/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:15:09 by cberganz          #+#    #+#             */
/*   Updated: 2021/12/09 11:22:52 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *save);
char	*save_cleaner(char *save);
char	*line_maker(char *save);
size_t	ft_strlen(const char *s);
char	*ft_join(char *s1, char *s2);
int		no_newline_in(char *save);

#endif
