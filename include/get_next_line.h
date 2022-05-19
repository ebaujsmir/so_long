/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:49 by esmirnov          #+#    #+#             */
/*   Updated: 2022/02/08 14:04:12 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_parse(char *str, char c);
int		ft_s_len(char *str);
char	*ft_strjoin_gnl(char *storage, char *buffer);
char	*ft_read(int fd, char *storage);
char	*ft_copy_before_n(char *storage);
char	*ft_copy_after_n(char *storage, char *line);
char	*get_next_line(int fd);

#endif
