/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:50 by hiipek            #+#    #+#             */
/*   Updated: 2024/12/28 18:32:57 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_line(char *dst, int fd);
char	*ft_get_line(char *dst);
char	*ft_get_left_line(char *buff);

size_t	ft_gnl_strlen(const char *str);
char	*ft_gnl_strchr(const char *str, int c);
char	*ft_gnl_strjoin(char *s1, char const *s2);

#endif