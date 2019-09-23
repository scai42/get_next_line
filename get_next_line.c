/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 23:55:07 by scai              #+#    #+#             */
/*   Updated: 2019/08/12 15:08:52 by scai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		bool_nl(int fd, char **line, char **f_tab)
{
	char	*f_heap;

	if (!*f_tab[fd])
		return (NO_NL_IE_CR_O_EOT);
	if (ft_strchr(f_tab[fd], '\n'))
	{
		*(f_tab[fd] + ft_strcspn(f_tab[fd], "\n")) = '\0';
		*line = ft_strdup(f_tab[fd]);
		f_heap = ft_strdup(ft_strchr(f_tab[fd], (char)0) + sizeof(char));
		free(f_tab[fd]);
		f_tab[fd] = ft_strdup(f_heap);
		free(f_heap);
	}
	else
	{
		*line = ft_strdup(f_tab[fd]);
		ft_memset((void *)f_tab[fd], 0, ft_strcspn(f_tab[fd], "\n")
				+ sizeof(char));
	}
	return (NL_FOUND);
}

int			get_next_line(const int fd, char **line)
{
	char		stack[BUFF_SIZE + sizeof(char)];
	char		*heap;
	static char	*f_tab[MAX_FD_SET];
	int		i;

	ERR_HAND(!(fd < 0 || BUFF_SIZE < 0 || !line || read(fd, 0, 0) < 0));
	if (!(f_tab[fd]))
		f_tab[fd] = ft_strnew(0);
	while (!(ft_strchr(f_tab[fd], 10)))
	{
		i = read(fd, stack, BUFF_SIZE);
		stack[i] = (char)0;
		if (i == 0)
			break ;
		heap = f_tab[fd];
		f_tab[fd] = ft_strjoin(heap, stack);
		free(heap);
	}
	return (bool_nl(fd, line, f_tab));
}
