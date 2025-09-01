/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:39:17 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:16 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*init_lst(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*modified_list;
	void	*new_content;

	new_content = f(lst->content);
	modified_list = ft_lstnew(new_content);
	if (!modified_list)
	{
		del(new_content);
		return (NULL);
	}
	return (modified_list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*modified_list;
	t_list	*modified_list_cpy;
	void	*new_content;

	if (!f || !del || !lst)
		return (NULL);
	modified_list = init_lst(lst, f, del);
	if (!modified_list)
		return (NULL);
	modified_list_cpy = modified_list;
	lst = lst->next;
	while (lst)
	{
		new_content = f(lst->content);
		modified_list->next = ft_lstnew(new_content);
		if (!modified_list->next)
		{
			del(new_content);
			ft_lstclear(&modified_list_cpy, del);
			return (NULL);
		}
		modified_list = modified_list->next;
		lst = lst->next;
	}
	return (modified_list_cpy);
}
