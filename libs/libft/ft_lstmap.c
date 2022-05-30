/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:46:09 by sbars             #+#    #+#             */
/*   Updated: 2021/12/20 14:33:12 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stdlib.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*node;

	node = ft_lstnew(f(lst->content));
	if (node && lst)
	{
		if (lst->next)
			node->next = ft_lstmap(lst->next, f, del);
	}
	else
		return (NULL);
	return (node);
}
