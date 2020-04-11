
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 10000

typedef struct		s_gnl
{
	char			*buff;
	char			*rest;
	char			*tmp;
	int				fd_s;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
