
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*s;

	if (!(s = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		s->content = NULL;
		s->content_size = 0;
	}
	else
	{
		if (!(s->content = malloc(sizeof(*(s->content)) * content_size)))
			return (NULL);
		s->content = ft_memcpy(s->content, content, content_size);
		s->content_size = content_size;
	}
	s->next = NULL;
	return (s);
}
