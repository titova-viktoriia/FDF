
#include "libft.h"

void	ft_strclr(char *s)
{
	int	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	ft_bzero(s, l);
}
