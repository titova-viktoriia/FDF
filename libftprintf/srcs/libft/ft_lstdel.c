
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ref;

	ref = *alst;
	if (!(alst) || !(*alst))
		return ;
	while (ref)
	{
		del(ref->content, ref->content_size);
		free(ref);
		ref = ref->next;
	}
	*alst = NULL;
}
