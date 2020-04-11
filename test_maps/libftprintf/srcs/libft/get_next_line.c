/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:07:53 by hdeckard          #+#    #+#             */
/*   Updated: 2019/10/02 21:53:03 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl			*get_new_list(t_gnl **head, const int fd)
{
	t_gnl				*lst;

	lst = *head;
	while (lst != NULL)
	{
		if (fd == lst->fd_s)
			return (lst);
		lst = lst->next;
	}
	if (!(lst = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	lst->fd_s = fd;
	if (!(lst->buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		free(lst);
		return (NULL);
	}
	lst->rest = NULL;
	lst->next = NULL;
	lst->tmp = NULL;
	if (*head)
		lst->next = *head;
	*head = lst;
	return (lst);
}

static void				change_line(t_gnl *list)
{
	char				*clone;

	if (list->rest != NULL)
	{
		list->tmp = ft_strdup(list->rest);
		ft_strdel(&(list->rest));
	}
	if (list->tmp == NULL)
	{
		list->tmp = ft_strdup(list->buff);
		return ;
	}
	else
	{
		clone = ft_strdup(list->tmp);
		ft_strdel(&(list->tmp));
		list->tmp = ft_strjoin(clone, list->buff);
		ft_strdel(&clone);
	}
}

static	void			split_line_and_rest(char **line, t_gnl *list)
{
	int					index;

	index = 0;
	if (list->rest != NULL)
	{
		list->tmp = ft_strdup(list->rest);
		ft_strdel(&(list->rest));
	}
	if (ft_strchr(list->tmp, '\n') == NULL)
	{
		*line = ft_strdup(list->tmp);
		ft_strdel(&(list->tmp));
		return ;
	}
	while (list->tmp[index] != '\n')
		index++;
	if (list->tmp[index + 1] != '\0')
		list->rest = ft_strdup((ft_strchr(list->tmp, '\n') + 1));
	if (list->tmp[0] != '\n')
		*line = ft_strsub(list->tmp, 0, index);
	else
		*line = ft_strdup("");
	ft_strdel(&(list->tmp));
}

int						get_next_line(const int fd, char **line)
{
	static t_gnl		*head;
	t_gnl				*list;
	int					readed;

	if (!(list = get_new_list(&head, fd)) || fd < 0 || !line
		|| read(fd, list->buff, 0) < 0)
		return (-1);
	if (list->rest != NULL && (ft_strchr(list->rest, '\n') != NULL))
	{
		split_line_and_rest(&(*line), list);
		return (1);
	}
	while ((readed = read(fd, list->buff, BUFF_SIZE)) > 0)
	{
		list->buff[readed] = '\0';
		change_line(list);
		if (ft_strchr(list->buff, '\n') != NULL)
			break ;
	}
	if (readed == 0 && list->tmp == NULL && list->rest == NULL)
		return (0);
	split_line_and_rest(&(*line), list);
	return (1);
}
