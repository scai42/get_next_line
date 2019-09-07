/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:11:56 by scai              #+#    #+#             */
/*   Updated: 2019/08/12 02:42:30 by scai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

# define ERR_HAND(x) if (!x) return (-1)
# define MAX_FD_SET 1024
# define NO_NL_IE_CR_OR_EOT 0
# define NL_FOUND 1

int	get_next_line(const int fd, char **line);
#endif
